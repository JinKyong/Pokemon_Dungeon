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
	//현재 이미지 & 상태
	dImage* _currentImg;
	POKEMON_STATE _state;

	//방향(==frameY) & frameX, count
	int _direct;
	int _frameX;
	float _count;

	//좌표 & Body
	float _x, _y;
	RECT _body;



	//이름
	wstring _name;

	//레벨 & 경험치
	int _level;
	int _EXP;



	//타입 & 특성
	POKEMON_TYPE _type;
	//특성 _passive;



	//스탯
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;



	//기술(스킬)
	//Skill _skill[4];

	//지닌도구(아이템)
	//Item _item;


public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual void changeState(POKEMON_STATE state) = 0;
	virtual void changeDirect(int direct) = 0;

	void controlFrame();


	//=================== 접근자 ===================//
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

