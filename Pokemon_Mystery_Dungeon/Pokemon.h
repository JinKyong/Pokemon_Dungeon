#pragma once
#include "PokemonType.h"

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
	int hp;
	int attack;
	int defense;
	int sattack;
	int sdefense;
	int speed;
}STAT, *PSTAT;


class Pokemon
{
protected:
	//���� �̹��� & ���� �� �ʻ�ȭ
	dImage* _currentImage;
	dImage* _stateImage[END_POKEMON_STATE];
	POKEMON_STATE _state;
	dImage* _portrait;

	//�̹��� ������ �� ī��Ʈ
	int _frameX;
	int _frameY;	//(== direct)
	float _angle;

	float _frameCount;					//frameCount
	float _count[END_POKEMON_STATE];	//frame�ѱ�� interval

	//���º� �̼�����
	float _tuningX;
	float _tuningY;
	bool _jump;

	//attack ���� ����
	float _interceptX;
	float _interceptY;
	float _gradient;
	float _tmpCount;
	bool _attack;






	//�̸� & ���� ��ȣ
	wstring _name;
	int _num;

	//����
	STAT _pokemonValue;

	//Ÿ�� & Ư��
	POKEMON_TYPE _type[2];

	//Ư�� _passive;

	//�����̻�
	//���� ���� : { ����, ����, ����, ��, ȭ��, ȥ��, ������, ��� }

	//����(��ü��)

	//��� �� �ִ� ���(��ų)
	//vector<int> _skill;
	//���������� ���� ���(��ų)
	//map<num, int>

	//��ȭ ����
	//int _revolution = 16; (16�� ��ȭ�Ѵٴ� ��) -> 0�̸� ��ȭ ����

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



	//=================== ������ ===================//
	dImage* getImage() { return _currentImage; }
	POKEMON_STATE getState() { return _state; }
	dImage* getPortrait() { return _portrait; }

	float getAngle() { return _angle; }
	int getDirect() { return _frameY; }
	void setDirect(int direct) { _frameY = direct; }

	bool getAttack() { return _attack; }
	void setAttack(bool attack) { _attack = attack; }

	wstring getName() { return _name; }
	int getNum() { return _num; }

	STAT getPokemonValue() { return _pokemonValue; }
};

