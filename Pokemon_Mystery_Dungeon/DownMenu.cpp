#include "stdafx.h"
#include "DownMenu.h"

void DownMenu::render()
{
	D2D1_RECT_F screen = CAMERAMANAGER->getScreen();

	_back->render(screen.left + _tuningX, screen.top + _tuningY, 0.5);
	//_back2->render(screen.left + _tuningX, screen.top + _tuningY, 0.5);
	_border->render(screen.left + _tuningX, screen.top + _tuningY);
	//_border2->render(screen.left + _tuningX, screen.top + _tuningY);

	//_arrow->render(screen.left + 80, screen.top + 80 + _index * 30);
}
