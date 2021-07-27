#include "stdafx.h"
#include "mainScene.h"

HRESULT mainScene::init(Player * player)
{
	Scene::init(player);

	TURNMANAGER->addAllPlayer(player);

	//배경 이미지
	for (int i = 0; i < 7; i++) {
		char keyName[128];
		WCHAR dirName[128];

		sprintf_s(keyName, "mainImage%d", i + 1);
		swprintf_s(dirName, L"img/title/%d.png", i + 1);
		_backImage[i] = IMAGEMANAGER->addDImage(keyName, dirName, 256, 192);
	}

	_currentImage = _backImage[RND->getInt(7)];

	UIMANAGER->changeUpMenu("titleMenu");
	UIMANAGER->changeDownMenu("titleMenu");

	SOUNDMANAGER->play("mainBGM");

	return S_OK;
}

void mainScene::release()
{
	SOUNDMANAGER->stop("mainBGM");
}

void mainScene::update()
{
	UIMANAGER->update();

	changeScene();
}

void mainScene::render()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	_currentImage->render(rc.left, rc.top, rc.left, rc.top,
		rc.right - rc.left, rc.bottom - rc.top);
	UIMANAGER->renderDown();
}

void mainScene::changeScene()
{
	if (CAMERAMANAGER->getAlpha() == 1.0) {
		//푸키몬이 있으면
		if(_player->getPokemon())
			SCENEMANAGER->changeScene("select");
		//없으면
		else {
		}
	}
}
