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
			L"모리스9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			15,
			L"ko-kr",
			&_dWDefaultFormat
		);
	}

	//Text Format이 생성되었으면 Text Brush 생성
	if (SUCCEEDED(hr)) {
		hr = _dRenderTarget->CreateSolidColorBrush(ColorF(ColorF::White), &_tBrush);
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
	if (_dFactory)			SAFE_RELEASE2(_dFactory);
	if (_dRenderTarget)		SAFE_RELEASE2(_dRenderTarget);
	if (_dBitRenderTarget)	SAFE_RELEASE2(_dBitRenderTarget);
	if (_dBitmap)			SAFE_RELEASE2(_dBitmap);
	if (_dBrush)			SAFE_RELEASE2(_dBrush);

	if (_dWFactory)			SAFE_RELEASE2(_dWFactory);
	if (_dWDefaultFormat)	SAFE_RELEASE2(_dWDefaultFormat);
	if (_dWCustomFormat)	SAFE_RELEASE2(_dWCustomFormat);
	if (_tBrush)			SAFE_RELEASE2(_tBrush);
}

void dtdManager::render(float destX, float destY, float width, float height)
{
	if (!_dRenderTarget) return;

	_dRenderTarget->BeginDraw();
	_dRenderTarget->Clear(ColorF(ColorF::Aquamarine));

	//위 화면
	UIMANAGER->renderUp();

	//아래 화면 (실제 게임 화면)
	D2D1_RECT_F dest = { destX, destY, destX + width, destY + height };
	D2D1_RECT_F sour = CAMERAMANAGER->getScreen();

	_dRenderTarget->DrawBitmap(_dBitmap, dest,
		1.0, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sour);

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

void dtdManager::printText(LPCWCHAR text, float x, float y, int width, int height)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, dRectMakeCenter(x, y, width, height), _tBrush);
}

void dtdManager::printText(LPCWCHAR text, float x, float y, int width, int height, float size)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"모리스9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"모리스9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}

	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, dRectMakeCenter(x, y, width, height), _tBrush);
}

void dtdManager::printText(LPCWCHAR text, D2D1_RECT_F rc)
{
	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWDefaultFormat, rc, _tBrush);
}

void dtdManager::printText(LPCWCHAR text, D2D1_RECT_F rc, float size)
{
	if (_dWCustomFormat) {
		if (_dWCustomFormat->GetFontSize() != size) {
			SAFE_RELEASE2(_dWCustomFormat);

			_dWFactory->CreateTextFormat(
				L"모리스9",
				nullptr,
				DWRITE_FONT_WEIGHT_NORMAL,
				DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL,
				size,
				L"ko-kr",
				&_dWCustomFormat
			);
		}
	}
	else {
		_dWFactory->CreateTextFormat(
			L"모리스9",
			nullptr,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			size,
			L"ko-kr",
			&_dWCustomFormat
		);
	}

	_dBitRenderTarget->DrawTextA(text, lstrlenW(text), _dWCustomFormat, rc, _tBrush);
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
		_dRenderTarget->CreateCompatibleRenderTarget(SizeF(width, height), &_dBitRenderTarget);
	}
}

void dtdManager::resetBrushColor()
{
	_dBrush->SetColor(ColorF(ColorF::Black));
}
