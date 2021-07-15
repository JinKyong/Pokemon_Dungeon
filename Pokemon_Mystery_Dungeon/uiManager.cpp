#include "stdafx.h"
#include "uiManager.h"

HRESULT uiManager::init()
{
	_screen = dRectMake(5 * WINSIZEX / 16, 0, 3 *  WINSIZEX / 8, 3 * WINSIZEY / 8);

	_testImage = IMAGEMANAGER->addDImage("testUPScreen", L"img/fade_B.png", 
		800, 600);
	//�̹��� �ҷ�����

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
}

void uiManager::render()
{
	DTDMANAGER->getRenderTarget()->DrawBitmap(_testImage->getBitmap(), _screen);
	//�̹��� ��Ʈ�� ��ũ�� ��Ʈ�� �׸��⸸ �ϸ� ��
}
