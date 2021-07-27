#include "stdafx.h"
#include "ResultMenu.h"
#include "Player.h"

HRESULT ResultMenu::init()
{
	//��� �̹���
	_back = IMAGEMANAGER->addDImage(
		"resultMenu_back", L"img/UI/resultMenu/back.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"resultMenu_border", L"img/UI/resultMenu/border.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);

	return S_OK;
}

void ResultMenu::release()
{
}

void ResultMenu::update()
{
	if (KEYMANAGER->isOnceKeyDown(KEY_A))
		CAMERAMANAGER->setFade(FADEOUT);
}

void ResultMenu::render()
{
	DownMenu::render();

	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();
	//D2D1_RECT_F dest = dRectMakeCenter((screen.left + screen.right) / 2, 145, 200, 200);

	D2D1_RECT_F dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 - 140,
		400, 100);

	WCHAR text[128];
	swprintf_s(text, L"%s(��)�� Ŭ�����ߴ�.", TILEMANAGER->getDungeonName().c_str());
	DTDMANAGER->printText(text, dest, 25, true);


	Player* player = (*TURNMANAGER->getAllPlayer())[0];

	//NAME, LEVEL, EXP
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 - 50,
		500, 50);
	swprintf_s(text, L"���ϸ� : %s  ���� : %d  ����ġ : %d",
		player->getPokemon()->getName().c_str(), player->getLevel(), player->getEXP());
	DTDMANAGER->printText(text, dest, 25, true);

	//HP, SPEED
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2,
		500, 50);
	swprintf_s(text, L"ü�� : %d \t ���ǵ� : %d",
		player->getRealStat().hp, player->getRealStat().speed);
	DTDMANAGER->printText(text, dest, 25, true);

	//ATTACK, DEFENSE
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 + 50,
		500, 50);
	swprintf_s(text, L"���� : %d \t ��� : %d",
		player->getRealStat().attack, player->getRealStat().defense);
	DTDMANAGER->printText(text, dest, 25, true);

	//SATTACK, SDEFENSE
	dest = dRectMakeCenter(
		(screen.left + screen.right) / 2, (screen.top + screen.bottom) / 2 + 100,
		500, 50);
	swprintf_s(text, L"Ư������ : %d \t Ư����� : %d",
		player->getRealStat().sattack, player->getRealStat().sdefense);
	DTDMANAGER->printText(text, dest, 25, true);
}
