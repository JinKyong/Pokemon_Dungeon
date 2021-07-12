#pragma once

#define ITEMSIZE 32 //item ������ �ִ� image�� ���� 32*32�Դϴ�

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
	RECT _body;				//�浹 �簢��
	dImage* _img;			//�̹���
	dImage* _imGummy[17];	//���� ������
	float _x, _y;			//x, y ��ǥ
	int _value;				//status�� ��ȭ ��
	wstring _name;			//�κ��丮 �̸�ǥ�ÿ�
	int _num;				//������ �ѹ�
	int _type;				//������ Ÿ��

	//====================throw====================//
	bool _isThrow;			//throw ������ ��������
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

	//������ ���
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