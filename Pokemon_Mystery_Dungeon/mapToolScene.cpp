#include "stdafx.h"
#include "mapToolScene.h"
#include "Enemy.h"
HRESULT mapToolScene::init(Player* player)
{
	Scene::init(player);
	_width = 80;
	_height = 45;
	CAMERAMANAGER->setBackScreenSize(TILEWIDTH*_width, TILEHEIGHT*_height);

	_maptool = new Maptool;
	_maptool->init();
	
	x = 0;
	y = 0;

	return S_OK;
}

void mapToolScene::release()
{
}

void mapToolScene::update()
{
	_maptool->update();
	if (KEYMANAGER->isStayKeyDown('W'))y-=47;
	if (KEYMANAGER->isStayKeyDown('A'))x-=47;
	if (KEYMANAGER->isStayKeyDown('S'))y+=47;
	if (KEYMANAGER->isStayKeyDown('D'))x+=47;

	if (x <= 0)x = 0;
	if (y <= 0)y = 0;
	if (x >= 3840)x = 3840;
	if (y >= 2160)y = 2160;
	CAMERAMANAGER->updateScreen(x, y);
}

void mapToolScene::render()
{
	
	
	D2D1_RECT_F rc = CAMERAMANAGER->getScreen();

	
	_maptool->render();
if (PRINTMANAGER->isDebug())
{
	WCHAR str[128];
	swprintf_s(str, L"_height: %d, _width: %d", _height, _width);
	DTDMANAGER->printText(str, x + 200, y + 200, 100, 100);
	swprintf_s(str, L"x: %d, y: %d, type: %d", x, y,_maptool->getType());
	DTDMANAGER->printText(str, x + 200, y + 100, 100, 100);
	_maptool->minimap();
}

}

void mapToolScene::changeScene()
{
}
