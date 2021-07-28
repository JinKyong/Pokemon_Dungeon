#include "stdafx.h"
#include "TitleMenuD.h"

HRESULT TitleMenuD::init()
{
	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"titleMenu_back", L"img/UI/titleMenu/back.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"titleMenu_border", L"img/UI/titleMenu/border.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);

	//���� ȭ��ǥ
	_arrow = IMAGEMANAGER->addDImage("selectTri", L"img/UI/mainMenu/tri.png", 10, 22);

	_tuningX = 0;
	_tuningY = 0;

	checkSave();

	_opacity = 1.0f;
	_count = 0;

	return S_OK;
}

void TitleMenuD::release()
{
}

void TitleMenuD::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_DOWN)) {
		SOUNDMANAGER->play("Index");
		_index = (_index + 1) % _maxIndex;
	}
	else if (KEYMANAGER->isOnceKeyDown(KEY_UP)) {
		SOUNDMANAGER->play("Index");
		_index = (_index - 1 + _maxIndex) % _maxIndex;
	}

	if (KEYMANAGER->isOnceKeyDown(KEY_A)) {
		if (_index == TITLEMENU_OPTION_NEW) {
			SOUNDMANAGER->play("Select");
			(*TURNMANAGER->getAllPlayer())[0]->init(RND->getInt(38) + 1, 25);
			(*TURNMANAGER->getAllPlayer())[0]->setSkill(4);
			CAMERAMANAGER->setFade(FADEOUT);
			_hidden = true;
		}
		else if (_index == TITLEMENU_OPTION_CONTINUE) {
			//�ε��ϰ�
			TXTDATA->loadGame((*TURNMANAGER->getAllPlayer())[0]);
			CAMERAMANAGER->setFade(FADEOUT);
			SOUNDMANAGER->play("Select");
			_hidden = true;
		}
	}

	_count++;
	if (_count > 20) {
		_opacity = !_opacity;
		_count = 0;
	}
}

void TitleMenuD::render()
{
	//if (_hidden) return;

	DownMenu::render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	_arrow->render(screen.left + 50, screen.top + 50 * _index + 60, _opacity);

	D2D1_RECT_F dest = dRectMake(screen.left + 80, screen.top + 55, 300, 300);

	DTDMANAGER->printText(L"�����ϱ�", dest, 30);

	if (!_hidden) {
		dest.top += 50;
		dest.bottom += 50;
		DTDMANAGER->printText(L"����ϱ�", dest, 30);
	}
}

void TitleMenuD::checkSave()
{
	char dir[256];
	char str[256];

	//���̺������� ������ -1//���ϸ� 
	sprintf_s(dir, "\\%s.ini", "data/saveData");

	//��ξ��
	GetCurrentDirectory(256, str);

	//��ο� ���ϸ� ��ġ��
	strncat_s(str, 256, dir, 254);

	//���� �ִ��� ������ �˻�
	//�ִٸ�
	if (INVALID_FILE_ATTRIBUTES != GetFileAttributes(str)) {
		_hidden = false;

		_maxIndex = END_TITLEMENU_OPTION;
	}
	//���ٸ�
	else if (INVALID_FILE_ATTRIBUTES == GetFileAttributes(str)) {
		_hidden = true;

		_maxIndex = END_TITLEMENU_OPTION - 1;
	}
}