#include "stdafx.h"
#include "gameNode.h"

gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init()
{
	_managerInit = false;

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_managerInit = managerInit;

	if (_managerInit)
	{
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		PRINTMANAGER->init();
		STREAMMANAGER->init();
		DTDMANAGER->init();
		CAMERAMANAGER->init();
		UIMANAGER->init();
		POKEDEX->init();
	}

	return S_OK;
}

void gameNode::release()
{
	if (_managerInit)
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->release();
		KEYMANAGER->releaseSingleton();

		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();

		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();

		PRINTMANAGER->release();
		PRINTMANAGER->releaseSingleton();

		STREAMMANAGER->release();
		STREAMMANAGER->releaseSingleton();

		DTDMANAGER->release();
		DTDMANAGER->releaseSingleton();

		CAMERAMANAGER->release();
		CAMERAMANAGER->releaseSingleton();

		UIMANAGER->release();
		UIMANAGER->releaseSingleton();

		POKEDEX->release();
		POKEDEX->releaseSingleton();

		CoUninitialize();
	}
}

void gameNode::update()
{
}

void gameNode::render()
{
}

void gameNode::cursorOnWindow()
{
	RECT rc;
	//윈도우 크기 RECT 생성
	GetClientRect(_hWnd, &rc);

	POINT pt1, pt2;

	//윈도우 LeftTop, RightTop점 좌표
	pt1.x = rc.left;
	pt1.y = rc.top;
	pt2.x = rc.right;
	pt2.y = rc.bottom;

	//변환
	ClientToScreen(_hWnd, &pt1);
	ClientToScreen(_hWnd, &pt2);

	//대입
	rc.left = pt1.x;
	rc.top = pt1.y;
	rc.right = pt2.x;
	rc.bottom = pt2.y;

	//마우스 고정
	ClipCursor(&rc);
}

void gameNode::setMap()
{
}

void gameNode::save()
{
}

void gameNode::load()
{
}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//	PAINTSTRUCT ps;
	//	HDC         hdc; //얘 찐 중요합니...

	switch (iMessage)
	{
		//마우스 움직이면 여기서 메세지 발생
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>(LOWORD(lParam));
		_ptMouse.y = static_cast<float>(HIWORD(lParam));

		if (_leftButtonDown) this->setMap();
		if (_rightButtonDown) this->setMap();

		break;
	case WM_LBUTTONDOWN:
		_leftButtonDown = true;
		this->setMap();

		break;
	case WM_LBUTTONUP:
		_leftButtonDown = false;

		break;
	case WM_RBUTTONDOWN:
		_rightButtonDown = true;
		this->setCtrlSelect(CTRL_ERASER);
		this->setMap();


		break;
	case WM_RBUTTONUP:
		_rightButtonDown = false;
		this->setCtrlSelect(CTRL_OBJDRAW);

		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case CTRL_SAVE:
			this->save();
			break;
		case CTRL_LOAD:
			this->load();
			InvalidateRect(hWnd, NULL, false);
			break;

		default:
			this->setCtrlSelect(LOWORD(wParam));
			break;
		}
		break;
	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;

	case WM_ACTIVATEAPP:
		//cursorOnWindow();
		break;

		//윈도우 창 부쉬는(?) 
	case WM_DESTROY:
		//윈도우 종료함수
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}