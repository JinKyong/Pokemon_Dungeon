#include "stdafx.h"
#include "dtdManager.h"

HRESULT dtdManager::init()
{
	release();

	_clear = true;

	HRESULT hr;

	//Fafctory 생성
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_dFactory);

	//Factory가 생성되었으면 RenderTarget 생성
	if (SUCCEEDED(hr)) {
		hr = _dFactory->CreateHwndRenderTarget(RenderTargetProperties(),
			HwndRenderTargetProperties(_hWnd, SizeU(WINSIZEX, WINSIZEY)),
			&_dRenderTarget);
	}

	//RenderTarget과 호환되는 또 다른 RenderTarget(=BackBuffer) 생성
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateCompatibleRenderTarget(SizeF(WINSIZEX, WINSIZEY),
			&_dBitRenderTarget);
	}

	//RenderTarget이 생성되었으면 Brush 생성
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateSolidColorBrush(ColorF(ColorF::Black), &_dBrush);
	}

	//Brush가 생성되었으면 Text Factory 생성
	if (SUCCEEDED(hr)) {
		hr = DWriteCreateFactory(
			DWRITE_FACTORY_TYPE_SHARED,
			__uuidof(IDWriteFactory),
			reinterpret_cast<IUnknown**>(&_dWFactory)
		);
	}

	//Text Factory가 생성되었으면 Text Format 생성
	if (SUCCEEDED(hr)) {
		hr = _dWFactory->CreateTextFormat(
			L"돋움",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			30.0f,
			L"ko-kr",
			&_dWFormat
		);
	}

	//Text Format이 생성되었으면 기본값(가운데 정렬) 설정
	/*if (SUCCEEDED(hr)) {
		hr = _dWFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);

		if (SUCCEEDED(hr)) {
			hr = _dWFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
		}
	}*/

	//wincodec(이미지 로더)을 사용하기 위함
	CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

	return S_OK;
}

void dtdManager::release()
{
	//동적 할당한 객체들 모두 해제
	if(_dFactory)			SAFE_RELEASE2(_dFactory);
	if(_dRenderTarget)		SAFE_RELEASE2(_dRenderTarget);
	if(_dBitRenderTarget)	SAFE_RELEASE2(_dBitRenderTarget);
	if(_dBitmap)			SAFE_RELEASE2(_dBitmap);
	if(_dBrush)				SAFE_RELEASE2(_dBrush);

	if(_dWFactory)			SAFE_RELEASE2(_dWFactory);
	if(_dWFormat)			SAFE_RELEASE2(_dWFormat);
}

void dtdManager::render()
{
	if (!_dRenderTarget) return;

	_dRenderTarget->BeginDraw();
	_dRenderTarget->Clear(ColorF(ColorF::White));

	D2D1_RECT_F dest = { 0, 0, WINSIZEX, WINSIZEY };
	D2D1_RECT_F sour = CAMERAMANAGER->getScreen();

	if (_dRenderTarget) {
		_dRenderTarget->DrawBitmap(_dBitmap, dest,
			1.0, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);
	}

	_dRenderTarget->EndDraw();
}

void dtdManager::beginDraw()
{
	if (_dBitRenderTarget) {
		_dBitRenderTarget->BeginDraw();
		_dBitRenderTarget->Clear();
	}
}

void dtdManager::endDraw()
{
	if (_dBitRenderTarget) {
		//SAFE_RELEASE2(_dBitmap);
		_dBitRenderTarget->GetBitmap(&_dBitmap);

		_dBitRenderTarget->EndDraw();
	}
}

void dtdManager::Rectangle(D2D1_RECT_F rc)
{
	if (_dBitRenderTarget)
		_dBitRenderTarget->DrawRectangle(rc, _dBrush);
}

void dtdManager::Rectangle(RECT rc)
{
	D2D1_RECT_F rect = { rc.left, rc.top, rc.right, rc.bottom };

	if (_dBitRenderTarget)
		_dBitRenderTarget->DrawRectangle(rect, _dBrush);
}

void dtdManager::printText(LPCWCHAR text, float x, float y, float width, float height)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWFormat, dRectMakeCenter(x, y, width, height), _dBrush);
}

void dtdManager::printText(LPCWCHAR text, D2D1_RECT_F rc)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWFormat, rc, _dBrush);
}

void dtdManager::setRotate(float angle, float x, float y)
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Rotation(angle, Point2F(x, y)));
}

void dtdManager::setScale(float sizeX, float sizeY, float x, float y)
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Scale(SizeF(sizeX, sizeY), Point2F(x, y)));
}

void dtdManager::resetTransform()
{
	_dBitRenderTarget->SetTransform(Matrix3x2F::Identity());
}

void dtdManager::setBackBuffer(float width, float height)
{
	SAFE_RELEASE2(_dBitRenderTarget);

	if (_dRenderTarget) {
		_dRenderTarget->CreateCompatibleRenderTarget(SizeF(width , height), &_dBitRenderTarget);
	}
}

void dtdManager::resetBrushColor()
{
	_dBrush->SetColor(ColorF(ColorF::Black));
}
