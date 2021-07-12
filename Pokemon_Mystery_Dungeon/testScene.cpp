#include "stdafx.h"
#include "testScene.h"
#include "Player.h"

HRESULT testScene::init(Player * player)
{
	Scene::init(player);

	CAMERAMANAGER->setBackScreenSize(3840, 2160);

	_back = IMAGEMANAGER->addDImage("back", L"img/sample1.jpg", 3840, 2160);

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	_player->update();
	CAMERAMANAGER->updateScreen(_player->getPokemon()->getX(), _player->getPokemon()->getY());
}

void testScene::render()
{
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();
	_back->render(rc.left, rc.top, rc.left, rc.top,
		rc.right - rc.left, rc.bottom - rc.top);

	_player->render();
}

void testScene::changeScene()
{
}