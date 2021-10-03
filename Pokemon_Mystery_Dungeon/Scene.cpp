#include "stdafx.h"
#include "Scene.h"

Player* Scene::_player = NULL;

HRESULT Scene::init(Player * player)
{
	_player = player;

	TURNMANAGER->init();

	return S_OK;
}