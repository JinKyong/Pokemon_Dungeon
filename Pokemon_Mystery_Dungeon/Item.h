#pragma once

#define ITEMSIZE 32 //item ������ �ִ� image�� ���� 32*32�Դϴ�

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
	RECT _body;				//�浹 �簢��
	dImage* _img;			//�̹���
	float _x, _y;			//x, y ��ǥ
	int _value;				//status�� ��ȭ ��
	wstring _name;			//�κ��丮 �̸�ǥ�ÿ�
	wstring _itemInfo;		//�κ��丮 ������ ���ټҰ�
	wstring _itemInfoLong;	//�κ��丮 ������ ����� �Ұ�
	int _num;				//������ �ѹ�
	int _type;				//������ Ÿ��

	bool _use;				//������ ��� ����

	//====================throw====================//
	bool _isThrow;			//throw ������ ��������
	float _fireX, _fireY;
	float _angle;
	//float _speed; -> Ÿ�ϻ����� �������� update������ ����

public:
	Item() {};
	~Item() {};

	virtual HRESULT init(float x, float y, float angle) = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();

	//������ ���
	//void useItem();	//���ξ� X

	//void eatItem(); //{ return ???; };
	//Item* giveItem() { return this; }; //��ȯ���� ������ ������
	
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
	wstring getItemInfo() { return _itemInfo; }
	wstring getitemInfoLong() { return _itemInfoLong; }

	bool getUse() { return _use; }
	void setUse() { _use = true; }

	RECT getBody() { return _body; }
	dImage* getImage() { return _img; }
};