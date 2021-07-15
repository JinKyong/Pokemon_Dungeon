#pragma once

#define ITEMSIZE 32 //item 폴더에 있는 image는 공통 32*32입니당

enum ITEMTYPE
{
	ITEM_FOOD,
	ITEM_HOLD,
	ITEM_TM,		
	ITEM_THROW,
	ITEM_ORB,
	ENDITEMTYPE //^^b
};

class Item
{
protected:
	RECT _body;				//충돌 사각형
	dImage* _img;			//이미지
	//*구미 -> 이미지 붙여서 프레임렌더
	float _x, _y;			//x, y 좌표
	int _value;				//status에 변화 줄
	wstring _name;			//인벤토리 이름표시용
	int _num;				//아이템 넘버
	int _type;				//아이템 타입

	bool _use;				//아이템 사용 여부

	//====================throw====================//
	bool _isThrow;			//throw 아이템 던졌는지
	float _fireX, _fireY;
	float _angle;
	//float _speed; -> 타일사이즈 기준으로 update때마다 갱신

public:
	Item() {};
	~Item() {};

	virtual HRESULT init(float x, float y, float angle) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();

	//아이템 사용
	//void useItem();	//도핑약 X

	//void eatItem(); //{ return ???; };
	//Item* giveItem() { return this; }; //반환값이 아이템 포인터
	
	//throw
	void throwItem(float x, float y, float angle);
	void itemMove();

	//get-set
	float getX() { return _x; }
	float getY() { return _y; }
	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }

	int getType() { return _type; }
	wstring getName() { return _name; } 

	bool getUse() { return _use; } //TM에 사용한CD 클래스를 하나더 만들라는거죠?

	RECT getBody() { return _body; }
	dImage* getImage() { return _img; }
};