#include "stdafx.h"
#include "TitleMenuD.h"

HRESULT TitleMenuD::init()
{
	//��� �̹���
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

	//if(���̺����Ϥ� ��������)
	//printText(����ϱ�)
	//������ �ε����� �ҷ��ͼ� �÷��̾� �̴Ͻ� ��Ű���

	//else(���̺������� ������)
	//printText(���ν���)
	//������ ǪŰ�� ����ȭ������
}
