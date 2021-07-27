#include "stdafx.h"
#include "loadingScene.h"

HRESULT loadingScene::init(Player * player)
{
	Scene::init(player);

	_back = IMAGEMANAGER->addDImage("loadingBack", L"img/fade_B.png", WINSIZEX, WINSIZEY);
	CAMERAMANAGER->setBackScreenSize(WINSIZEX, WINSIZEY);

	//�����带 �Ẹ�ʽô�
	CreateThread(
		NULL,			//�������� ���ȼӼ�(�ڽ������찡 �����Ҷ�)
		NULL,			//�������� ����ũ��(NULL�� �θ� ���ξ�����)
		threadFunction,	//����� �Լ�
		this,			//������ �Ű�����(this�� ������ �� Ŭ����)
		NULL,			//������ Ư��(��ٸ��� �ٷν�������(NULL))
		NULL			//������ ���� �� �������� ID �Ѱ���
	);

	_currentCount = 0;
	_create = false;

	return S_OK;
}

void loadingScene::release()
{
}

void loadingScene::update()
{
	changeScene();
}

void loadingScene::render()
{
	_back->render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	D2D1_RECT_F dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 - 100,
		300, 200);

	WCHAR text[128];
	swprintf_s(text, L"%s", TILEMANAGER->getDungeonName().c_str());
	DTDMANAGER->printText(text, dest, 50, true);

	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2,
		200, 100);
	//�ö󰡴� �����̸�
	swprintf_s(text, L"%dF", TILEMANAGER->getFloor());
	//�������� �����̸�
	DTDMANAGER->printText(text, dest, 50, true);
}

void loadingScene::changeScene()
{
	if (_currentCount >= LOADINGMAX)
	{
		CAMERAMANAGER->setFade(FADEOUT);

		if(CAMERAMANAGER->getAlpha() == 1.0)
			SCENEMANAGER->changeScene("dungeon");
	}
}

DWORD loadingScene::threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;

	//�ʿ��� �̹����� ���� ���⿡�� �߰��Ͻø� �˴ϴ�

	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		if (!loadingHelper->_create) {
			srand(time(NULL));
			TILEMANAGER->init();
			loadingHelper->_create = true;
		}

		//�̷��� ���ϸ� �� ������
		Sleep(1);

		loadingHelper->_currentCount++;
	}

	return 0;
}
