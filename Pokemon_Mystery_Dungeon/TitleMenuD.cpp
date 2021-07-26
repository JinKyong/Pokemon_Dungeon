#include "stdafx.h"
#include "TitleMenuD.h"

HRESULT TitleMenuD::init()
{
	//배경 이미지
	_back = IMAGEMANAGER->addDImage(
		"titleMenu_back", L"img/UI/titleMenu/back.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"titleMenu_border", L"img/UI/titleMenu/border.png", DOWNMENU_WIDTH, DOWNMENU_HEIGHT);

	_tuningX = 0;
	_tuningY = 0;

	_hidden = true;

	return S_OK;
}

void TitleMenuD::release()
{
}

void TitleMenuD::update()
{
}

void TitleMenuD::render()
{
	DownMenu::render();

	//if(세이브파일ㅇ ㅣ있으면)
	//printText(계속하기)
	//누르면 로드파일 불러와서 플레이어 이니시 시키면됨

	//else(세이브파일이 없으면)
	//printText(새로시작)
	//누르면 푸키몬 선택화면으로
}
