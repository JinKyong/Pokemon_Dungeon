#include "stdafx.h"
#include "loadingScene.h"

HRESULT loadingScene::init(Player * player)
{
	Scene::init(player);

	_back = IMAGEMANAGER->addDImage("loadingBack", L"img/fade_B.png", WINSIZEX, WINSIZEY);
	CAMERAMANAGER->setBackScreenSize(WINSIZEX, WINSIZEY);

	//쓰레드를 써보십시다
	CreateThread(
		NULL,			//스레드의 보안속성(자신윈도우가 존재할때)
		NULL,			//스레드의 스택크기(NULL로 두면 메인쓰레드)
		threadFunction,	//사용할 함수
		this,			//스레드 매개변수(this로 뒀으니 본 클래스)
		NULL,			//스레드 특성(기다릴지 바로실행할지(NULL))
		NULL			//스레드 생성 후 스레드의 ID 넘겨줌
	);

	playSound();

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
	//올라가는 던전이면
	swprintf_s(text, L"%dF", TILEMANAGER->getFloor());
	//내려가는 던전이면
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

void loadingScene::playSound()
{
	char music[128];

	switch (TILEMANAGER->getType()) {
	case 0:
		sprintf_s(music, "Mt.Bristle");
		break;
	case 1:
		sprintf_s(music, "Concealed Ruins");
		break;
	case 2:
		sprintf_s(music, "Amp Plains");
		break;
	case 3:
		sprintf_s(music, "Brine Cave");
		break;
	case 4:
		sprintf_s(music, "Waterfall Cave");
		break;
	case 5:
		sprintf_s(music, "Apple Woods");
		break;
	case 6:
		sprintf_s(music, "Craggy Coast");
		break;
	case 7:
		sprintf_s(music, "Mt.Horn");
		break;
	default:
		sprintf_s(music, "");
		break;
	}

	if(!SOUNDMANAGER->isPlaySound(music))
		SOUNDMANAGER->play(music);
}

DWORD loadingScene::threadFunction(LPVOID lpParameter)
{
	loadingScene* loadingHelper = (loadingScene*)lpParameter;

	//필요한 이미지랑 사운드 여기에서 추가하시면 됩니다

	while (loadingHelper->_currentCount != LOADINGMAX)
	{
		if (!loadingHelper->_create) {
			srand(time(NULL));
			TILEMANAGER->init();
			loadingHelper->_create = true;
		}

		//이렇게 안하면 휙 지나감
		Sleep(1);

		loadingHelper->_currentCount++;
	}

	return 0;
}
