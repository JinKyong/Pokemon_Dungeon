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
	P_DEFAULT,
	END_POKEMON_STATE
};

class Pokemon
{
protected:
	//현재 이미지 & 상태
	dImage* _currentImage;
	dImage* _stateImage[END_POKEMON_STATE];
	POKEMON_STATE _state;

	//이미지 프레임 및 카운트
	int _frameX;
	int _frameY;	//(== direct)
	float _angle;
	float _idleCount;					//DEFAULT상태일 때, IDLE로 가는 interval
	float _frameCount;					//frameCount
	float _count[END_POKEMON_STATE];	//frame넘기는 interval

	//이름 & 도감 번호
	wstring _name;
	int _num;

	//타입 & 특성
	POKEMON_TYPE _type;
	//특성 _passive;

	//스탯(개체값)
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;



	//배울 수 있는 기술(스킬)
	//vector<int> _skill;
	//레벨업으로 배우는 기술(스킬)
	//map<num, int>

	//진화 레벨
	//int _revolution = 16; (16에 진화한다는 뜻) -> 0이면 진화 안함


public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render(float x, float y) = 0;

	void controlFrame();

	void changeDirect(int direct);
	void changeState(POKEMON_STATE state);



	//=================== 접근자 ===================//
	dImage* getImage() { return _currentImage; }

	POKEMON_STATE getState() { return _state; }

	int getDirect() { return _frameY; }
	void setDirect(int direct) { _frameY = direct; }

	wstring getName() { return _name; }
};

