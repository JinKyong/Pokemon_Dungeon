#include "stdafx.h"
#include "TitleMenuU.h"

HRESULT TitleMenuU::init()
{
	UpMenu::init();

	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"titleMenu_UP", L"img/UI/titleMenu/keySetting.png", UPMENU_WIDTH, UPMENU_HEIGHT);

	return S_OK;
}

void TitleMenuU::release()
{
}

void TitleMenuU::update()
{
}

void TitleMenuU::render()
{
	UpMenu::render();
}
