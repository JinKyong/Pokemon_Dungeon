#pragma once
#include "PokemonType.h"

#define RIGHT	0x00000001
#define LEFT	0x00000002
#define UP		0x00000004
#define DOWN	0x00000008

enum POKEMON_STATE {
	POKEMON_STATE_IDLE,
	POKEMON_STATE_MOVE,
	POKEMON_STATE_ATTACK,
	POKEMON_STATE_SATTACK,
	POKEMON_STATE_HURT,
	POKEMON_STATE_SLEEP,
	POKEMON_STATE_DEFAULT,
	END_POKEMON_STATE
};

typedef struct tagPokemonStat {
	int _hp;
	int _attack;
	int _defense;
	int _sattack;
	int _sdefense;
	int _speed;
}STAT, *PSTAT;


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

	float _frameCount;					//frameCount
	float _count[END_POKEMON_STATE];	//frame넘기는 interval

	//상태별 미세조정
	float _tuningX;
	float _tuningY;
	bool _jump;

	//attack 관련 변수
	float _interceptX;
	float _interceptY;
	float _gradient;
	float _tmpCount;






	//이름 & 도감 번호
	wstring _name;
	int _num;

	//스탯
	STAT _pokemonValue;

	//타입 & 특성
	POKEMON_TYPE _type[2];

	//특성 _passive;

	//상태이상
	//현재 상태 : { 얼음, 수면, 마비, 독, 화상, 혼란, 헤롱헤롱, 노멀 }

	//스탯(개체값)

	//배울 수 있는 기술(스킬)
	//vector<int> _skill;
	//레벨업으로 배우는 기술(스킬)
	//map<num, int>

	//진화 레벨
	//int _revolution = 16; (16에 진화한다는 뜻) -> 0이면 진화 안함

public:
	virtual HRESULT init() = 0;
	virtual void release() = 0;

	void update();
	void render(float x, float y);


	void controlFrame();
	void changeDirect(int direct);
	void changeState(POKEMON_STATE state);


	void tuneIdle();
	void tuneAttack();
	void tuneHurt();
	float attackRange(float x);



	//=================== 접근자 ===================//
	dImage* getImage() { return _currentImage; }

	POKEMON_STATE getState() { return _state; }

	float getAngle() { return _angle; }

	int getDirect() { return _frameY; }
	void setDirect(int direct) { _frameY = direct; }

	wstring getName() { return _name; }
	int getNum() { return _num; }

	STAT getPokemonValue() { return _pokemonValue; }
};

