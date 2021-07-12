#pragma once

#define ITEMSIZE 32 //item 폴더에 있는 image는 공통 32*32입니당

enum ITEMTYPE
{
	FOOD,
	HOLD,
	TM,
	THROW,
	ENDITEMTYPE
};

class Item
{
protected:
	RECT _body;				//충돌 사각형
	dImage* _img;			//이미지
	dImage* _imGummy[17];	//구미 렌더용
	float _x, _y;			//x, y 좌표
	int _value;				//status에 변화 줄
	wstring _name;			//인벤토리 이름표시용
	int _num;				//아이템 넘버
	int _type;				//아이템 타입

	//====================throw====================//
	bool _isThrow;			//throw 아이템 던졌는지
	float _fireX, _fireY;
	float _angle;
	float _speed;

public:
	Item() {};
	~Item() {};

	virtual HRESULT init(float x, float y) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;

	//아이템 사용
	virtual void useItem() = 0;
	virtual void throwItem(float x, float y, float angle) = 0;
	
	//throw
	virtual void itemMove(float x, float y, float angle) = 0;

	//get-set
	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	virtual int getType() { return _type; }

	RECT getBody() { return _body; }
	dImage* getImage() { return _img; }
};