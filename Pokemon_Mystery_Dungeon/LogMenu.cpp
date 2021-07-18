#include "stdafx.h"
#include "LogMenu.h"

HRESULT LogMenu::init()
{
	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"logMenu_back", L"img/UI/logMenu/back.png", LOGMENU_WIDTH, LOGMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"logMenu_border", L"img/UI/logMenu/border.png", LOGMENU_WIDTH, LOGMENU_HEIGHT);

	_tuningX = 0;
	_tuningY = 0;

	_logList = DIALOGMANAGER->getBattleLog();

	_hidden = true;

	return S_OK;
}

void LogMenu::release()
{
}

void LogMenu::update()
{
	if (TIMEMANAGER->clock() >= 4) {
		_hidden = true;
		TIMEMANAGER->endTimer();
	}
}

void LogMenu::render()
{
	if (_hidden) return;

	DownMenu::render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	logIter iter = _logList->begin();
	int count = 0;

	for (; iter != _logList->end(); ++iter) {

		DTDMANAGER->printText(iter->c_str(), 
			screen.left + LOGMENU_WIDTH / 2, screen.bottom - 144 + count * 20,
			480, 20, 20);
		count++;
	}
}
