#include "stdafx.h"
#include "InvenMenu.h"

HRESULT InvenMenu::init()
{
	_back = IMAGEMANAGER->addDImage(
		"mainMenu_back", L"img/UI/mainMenu/back.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);
	_border = IMAGEMANAGER->addDImage(
		"mainMenu_border", L"img/UI/mainMenu/border.png", INVENMENU_WIDTH, INVENMENU_HEIGHT);

	_index = 0;

	//���Ʒ��� �������� �ε��� +- (������� Ŀ����X 0���� �۾Ƶ� X)
	//������ �ѱ�� +- 8 (*����ó�� �ʼ�)

	return S_OK;
}

void InvenMenu::release()
{
	//�Ƹ� X? �Ѵٸ� ���� ������->null�� �ٲ�..�ִ�..? (����? ����?)
}

void InvenMenu::update()
{
	//����Ű ��ġ!
}

void InvenMenu::render()
{
	//�̸��� ����
	//Ʋ??�̿�?
	//hidden..... ���� ����(����â?)â ��������
	//â�� ��������ҰŰ��ƿ�
}
