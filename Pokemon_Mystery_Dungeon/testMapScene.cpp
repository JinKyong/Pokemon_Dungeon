#include "stdafx.h"
#include "testMapScene.h"

HRESULT testMapScene::init(Player * player)
{
	Scene::init(player);
	_width = 80;
	_height = 45;
	CAMERAMANAGER->setBackScreenSize(TILEWIDTH*_width, TILEHEIGHT*_height);

	_sample = new sampleMap;
	_sample->init();

	x = 0;
	y = 0;
	return S_OK;
}

void testMapScene::release()
{
}

void testMapScene::update()
{
	if (KEYMANAGER->isStayKeyDown('W'))y -= 47;
	if (KEYMANAGER->isStayKeyDown('A'))x -= 47;
	if (KEYMANAGER->isStayKeyDown('S'))y += 47;
	if (KEYMANAGER->isStayKeyDown('D'))x += 47;
	CAMERAMANAGER->updateScreen(x, y);
}

void testMapScene::render()
{
	_sample->render();
}

void testMapScene::changeScene()
{
}

//void testMapScene::mapset()
//{
//	_maptool->example(1, 0, 0, 0, OBJ_NONE);
//	_maptool->example(2, 0, 0, 0, OBJ_NONE);
//}
