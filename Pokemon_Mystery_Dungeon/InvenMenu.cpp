#include "stdafx.h"
#include "InvenMenu.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"mainMenu_back", L"img/UI/mainMenu/back.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"mainMenu_border", L"img/UI/mainMenu/border.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_index = 0;

	//위아래로 갈때마다 인덱스 +- (사이즈보다 커져도X 0보다 작아도 X)
	//옆으로 넘기면 +- 8 (*예외처리 필수)

	return S_OK;
}

void InvenMenu::release()
{
	//아마 X? 한다면 벡터 포인터->null로 바꿔..주는..? (선택? 굳이?)
}

void InvenMenu::update()
{
	//조작키 위치!
}

void InvenMenu::render()
{
	//이름을 렌더
	//틀??이요?
	//hidden..... 으로 작은(선택창?)창 가려놓기
	//창고 열어봐야할거같아여
}
