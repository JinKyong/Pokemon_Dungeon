#pragma once
#include "singletonBase.h"

class dtdManager : public singletonBase<dtdManager>
{
private:
	//Factory, RenderTarget
	ID2D1Factory			*_dFactory;
	ID2D1HwndRenderTarget	*_dRenderTarget;
	ID2D1BitmapRenderTarget	*_dBitRenderTarget;
	ID2D1Bitmap				*_dBitmap;

	//Brush
	ID2D1BitmapBrush		*_dBitmapBrush;
	ID2D1SolidColorBrush	*_dBrush;

	//Text
	IDWriteFactory			*_dWFactory;
	IDWriteTextFormat		*_dWFormat;

	bool _clear;

public:
	HRESULT init();
	void release();
	void render();

	void beginDraw();
	void endDraw();

	void Rectangle(D2D1_RECT_F rc);
	void Rectangle(RECT rc);
	void printText(LPCWCHAR text, float x, float y, float width, float height);
	void printText(LPCWCHAR text, D2D1_RECT_F rc);

	//ȸ��
	void setRotate(float angle, float x, float y);
	//ũ������
	void setScale(float sizeX, float sizeY, float x, float y);
	//����
	void resetTransform();

	//����� ������ �缳��
	void setBackBuffer(float width, float height);

	void resetBrushColor();
	D2D1_COLOR_F getBrushColor() { return _dBrush->GetColor(); }
	void setBrushColor(D2D1_COLOR_F color) { _dBrush->SetColor(color); }

	ID2D1HwndRenderTarget* getRenderTarget() { return _dRenderTarget; }
	ID2D1BitmapRenderTarget* getBitRenderTarget() { return _dBitRenderTarget; }

	void setClear(bool clear) { _clear = clear; }
	bool getClear() { return _clear; }
};

