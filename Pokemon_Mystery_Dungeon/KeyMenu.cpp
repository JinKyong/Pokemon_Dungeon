#include "stdafx.h"
#include "KeyMenu.h"

HRESULT KeyMenu::init()
{
	UpMenu::init();

	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"keyMenu_back", L"img/UI/keyMenu/back.png", UPMENU_WIDTH, UPMENU_HEIGHT);

	return S_OK;
}

void KeyMenu::release()
{
}

void KeyMenu::update()
{
}

void KeyMenu::render()
{
	UpMenu::render();
}
