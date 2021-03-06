#include "stdafx.h"
#include "Mawile.h"

Mawile::Mawile()
{
	//이름
	_name = L"입치트";
	_num = 29;


	//스탯(개체값)
	_pokemonValue.hp = 50;
	_pokemonValue.attack = 85;
	_pokemonValue.defense = 85;
	_pokemonValue.sattack = 55;
	_pokemonValue.sdefense = 55;
	_pokemonValue.speed = 50;


	//타입 & 특성
	_type[0] = POKEMON_TYPE_STEEL;
	_type[1] = END_POKEMON_TYPE;

	_jump = false;
}

Mawile::~Mawile()
{
}

HRESULT Mawile::init()
{
	Pokemon::init();

	//이미지
	_stateImage[POKEMON_STATE_IDLE] = IMAGEMANAGER->addFrameDImage("mawile_idle",
		L"img/pokemon/29. mawile/idle.png", 148, 682, 2, 11);
	_stateImage[POKEMON_STATE_MOVE] = IMAGEMANAGER->addFrameDImage("mawile_move",
		L"img/pokemon/29. mawile/move.png", 296, 682, 4, 11);
	_stateImage[POKEMON_STATE_ATTACK] = IMAGEMANAGER->addFrameDImage("mawile_attack",
		L"img/pokemon/29. mawile/attack.png", 148, 682, 2, 11);
	_stateImage[POKEMON_STATE_SATTACK] = IMAGEMANAGER->addFrameDImage("mawile_sattack",
		L"img/pokemon/29. mawile/sattack.png", 196, 1078, 2, 11);
	_stateImage[POKEMON_STATE_HURT] = IMAGEMANAGER->addFrameDImage("mawile_hurt",
		L"img/pokemon/29. mawile/hurt.png", 78, 858, 1, 11);
	_stateImage[POKEMON_STATE_SLEEP] = IMAGEMANAGER->addFrameDImage("mawile_sleep",
		L"img/pokemon/29. mawile/sleep.png", 108, 44, 2, 1);
	_stateImage[POKEMON_STATE_DEFAULT] = IMAGEMANAGER->addFrameDImage("mawile_default",
		L"img/pokemon/29. mawile/default.png", 74, 682, 1, 11);

	//초상화
	_portrait = IMAGEMANAGER->addDImage("mawile_portrait",
		L"img/pokemon/29. mawile/portrait.png", 40, 40);

	//frame
	changeDirect(DOWN);
	changeState(POKEMON_STATE_DEFAULT);

	//frameCount(포켓몬마다 조정해줘야함)
	_count[POKEMON_STATE_IDLE] = 0.8 / (_stateImage[POKEMON_STATE_IDLE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_MOVE] = 0.8 / (_stateImage[POKEMON_STATE_MOVE]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_ATTACK] = 0.8 / (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_SATTACK] = 0.8 / (_stateImage[POKEMON_STATE_SATTACK]->getMaxFrameX() + 1);
	_count[POKEMON_STATE_HURT] = 1.0;
	_count[POKEMON_STATE_SLEEP] = 0.5;
	_count[POKEMON_STATE_DEFAULT] = 0.8;

	//상태별 미세조정
	_tuningX = 0;
	_tuningY = 0;

	//attack 2차 함수
	_interceptX = _count[POKEMON_STATE_ATTACK] * (_stateImage[POKEMON_STATE_ATTACK]->getMaxFrameX() + 1);
	_interceptY = 3 * TILEWIDTH / 4;
	_gradient = -_interceptY / (_interceptX * _interceptX);

	//스킬 목록
	_skill.push_back(4);
	_skill.push_back(5);
	_skill.push_back(7);
	_skill.push_back(8);
	_skill.push_back(9);
	_skill.push_back(10);
	_skill.push_back(14);
	_skill.push_back(16);
	_skill.push_back(17);
	_skill.push_back(18);
	_skill.push_back(21);


	return S_OK;
}
