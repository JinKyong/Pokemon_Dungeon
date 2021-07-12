#pragma once

#define RIGHT	0x00000001
#define LEFT	0x00000002
#define UP		0x00000004
#define DOWN	0x00000008

#define PSIZEX	48
#define PSIZEY	48

enum POKEMON_TYPE {
	TYPE_NORMAL,
	TYPE_FIRE,
	TYPE_WATER,
	TYPE_GRASS,
	TYPE_ELECTRIC,
	TYPE_ICE,
	TYPE_FIGHTING,
	TYPE_POISON,
	TYPE_GROUND,
	TYPE_FLYING,
	TYPE_PSYCHIC,
	TYPE_BUG,
	TYPE_ROCK,
	TYPE_GHOST,
	TYPE_DRAGON,
	TYPE_DARK,
	TYPE_STEEL,
	END_POKEMON_TYPE
};

enum POKEMON_STATE {
	P_IDLE,
	P_MOVE,
	P_ATTACK,
	P_SATTACK,
	P_HURT,
	P_SLEEP,
	END_POKEMON_STATE
};

class Pokemon
{
protected:
	//���� �̹��� & ����
	dImage* _currentImg;
	POKEMON_STATE _state;

	//����(==frameY) & frameX, count
	int _direct;
	int _frameX;
	float _count;

	//��ǥ & Body
	float _x, _y;
	RECT _body;



	//�̸�
	wstring _name;

	//���� & ����ġ
	int _level;
	int _EXP;



	//Ÿ�� & Ư��
	POKEMON_TYPE _type;
	//Ư�� _passive;



	//����
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;



	//���(��ų)
	//Skill _skill[4];

	//���ѵ���(������)
	//Item _item;


public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void changeState(POKEMON_STATE state) = 0;
	virtual void changeDirect(int direct) = 0;

	void controlFrame();


	//=================== ������ ===================//
	int getDirect() { return _direct; }
	void setDirect(int direct) { _direct = direct; }

	float getX() { return _x; }
	void setX(float x) { _x = x; }
	float getY() { return _y; }
	void setY(float y) { _y = y; }
	RECT getBody() { return _body; }
	void setBody(float x, float y, int width, int height) { _body = RectMakeCenter(x, y, width, height); }

	wstring getName() { return _name; }
};

