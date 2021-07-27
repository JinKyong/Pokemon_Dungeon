#include "stdafx.h"
#include "TitleMenuD.h"

HRESULT TitleMenuD::init()
{
	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"titleMenu_back", L"img/UI/titleMenu/back.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"titleMenu_border", L"img/UI/titleMenu/border.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);

	//선택 화살표
	_arrow = IMAGEMANAGER->addDImage("selectTri", L"img/UI/mainMenu/tri.png", 10, 22);

	_tuningX = 0;
	_tuningY = 0;

	_hidden = false;

	//세이브파일이 없으면 -1
	_maxIndex = END_TITLEMENU_OPTION;

	_opacity = 1.0f;
	_count = 0;

	return S_OK;
}

void TitleMenuD::release()
{
	SOUNDMANAGER->stop("Index");
	SOUNDMANAGER->stop("Select");
}

void TitleMenuD::update()
{
	if (_hidden) return;

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
			//로드하고
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
	if (_hidden) return;

	DownMenu::render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	_arrow->render(screen.left + 50, screen.top + 50 * _index + 60, _opacity);

	D2D1_RECT_F dest = dRectMake(screen.left + 80, screen.top + 55, 300, 300);

	DTDMANAGER->printText(L"새로하기", dest, 30);

	if (_maxIndex == END_TITLEMENU_OPTION) {
		dest.top += 50;
		dest.bottom += 50;
		DTDMANAGER->printText(L"계속하기", dest, 30);
	}
}
