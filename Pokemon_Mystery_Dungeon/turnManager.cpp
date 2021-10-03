#include "stdafx.h"
#include "turnManager.h"
#include "Enemy.h"

HRESULT turnManager::init()
{
	_order = 0;
	_input = true;

	_currentProgressTurn = POKEMON_STATE_DEFAULT;
	_pause = false;

	return S_OK;
}

void turnManager::release()
{
	playerIter player = _inputPlayerList.begin();

	for (; player != _inputPlayerList.end();)
		player = _inputPlayerList.erase(player);


	player = _allPlayerList.begin();

	for (; player != _allPlayerList.end();)
	{
		if ((*player)->getPlayerType() == PLAYER_TYPE_ENEMY) {
			(*player)->release();
			SAFE_DELETE((*player));
			player = _allPlayerList.erase(player);
		}
		else
			++player;
	}


	_pause = false;

	//_allPlayerList.clear();
}

void turnManager::update()
{
	if (_input)
		inputFromPlayer();

	else {	//�Է��� ������ ����

		//�� �Ͻ�����
		if (_pause) return;

		playerIter player;

		//������ ����
		player = _allPlayerList.begin();
		for (; player != _allPlayerList.end(); ++player) {
			if ((*player)->getPokemon()->getDeath()) {
				//����ġ ȹ��
				if ((*player)->getPlayerType() == PLAYER_TYPE_ENEMY) {
					int exp = BATTLEMANAGER->EXPCalculation(*player);
					DIALOGMANAGER->addExpLog(_allPlayerList[0], exp);
					_allPlayerList[0]->addEXP(exp);
				}

				//������ ������ ����ȭ������
				if ((*player)->getPlayerType() == PLAYER_TYPE_USER) {
					_allPlayerList.erase(player);

					TILEMANAGER->stopBGM();
					_inputPlayerList.clear();
					CAMERAMANAGER->setFade(FADEOUT);
					return;
				}
				else
					_allPlayerList.erase(player);

				break;
			}
		}
		player = _inputPlayerList.begin();
		for (; player != _inputPlayerList.end(); ++player) {
			if ((*player)->getPokemon()->getDeath()) {
				_inputPlayerList.erase(player);
				break;
			}
		}

		//�տ������� ���ʴ��
		if ((player = _inputPlayerList.begin()) != _inputPlayerList.end()) {
			_currentProgressTurn = (*player)->getPlayerState();

			for (; player != _inputPlayerList.end();) {
				if ((*player)->getPlayerState() != _currentProgressTurn) break;

				(*player)->update();

				if (_currentProgressTurn == POKEMON_STATE_ATTACK ||
					_currentProgressTurn == POKEMON_STATE_SATTACK)
					break;

				else if (_currentProgressTurn == END_POKEMON_STATE) {
					COLLISIONMANAGER->collisionEndTurnPlayer((*player));
					//(*player)->getPokemon()->changeState(POKEMON_STATE_DEFAULT);
					(*player)->resetXY();
					player = _inputPlayerList.erase(player);
				}

				else
					++player;
			}
		}
		else {
			_order = 0;
			_input = true;

			if (!RND->getInt(25))
				randomAddEnemy();
		}
	}
}

void turnManager::render()
{
	//��� �÷��̾� render
	playerIter player = _allPlayerList.begin();
	for (; player != _allPlayerList.end(); ++player) {
		if ((*player) == getCurrentPlayer()) continue;
		(*player)->render();
	}
	if(getCurrentPlayer())
		getCurrentPlayer()->render();
}

void turnManager::randomSetting()
{
	//���ʹ� �߰�
	vector<int> enemyList = TILEMANAGER->getEnemyList();
	int number = RND->getFromIntTo(3, 6);
	int minLevel = TILEMANAGER->getMinLevel();
	int maxLevel = TILEMANAGER->getMaxLevel();

	for (int i = 0; i < number; i++) {
		Player* enemy = new Enemy;
		enemy->init(enemyList[RND->getInt(enemyList.size())], RND->getFromIntTo(minLevel, maxLevel));
		addAllPlayer(enemy);
	}




	//���� ��ġ
	vector<RECT>* room = TILEMANAGER->getvRoom();

	playerIter player = _allPlayerList.begin();

	for (; player != _allPlayerList.end();) {
		int index = RND->getInt(room->size());

		float x = RND->getFromIntTo((*room)[index].left, (*room)[index].right);
		float y = RND->getFromIntTo((*room)[index].top, (*room)[index].bottom);

		(*player)->initXY(x, y);
		++player;
	}


	int index1 = RND->getInt(room->size());
	int index2 = RND->getInt(room->size());
	int index3 = RND->getInt(room->size());

	float x1 = RND->getFromIntTo((*room)[index1].left, (*room)[index1].right);
	float y1 = RND->getFromIntTo((*room)[index1].top, (*room)[index1].bottom);
	float x2 = RND->getFromIntTo((*room)[index2].left, (*room)[index2].right);
	float y2 = RND->getFromIntTo((*room)[index2].top, (*room)[index2].bottom);
	float x3 = RND->getFromIntTo((*room)[index3].left, (*room)[index3].right);
	float y3 = RND->getFromIntTo((*room)[index3].top, (*room)[index3].bottom);
}

void turnManager::randomAddEnemy()
{
	//���ʹ� ��������
	vector<int> enemyList = TILEMANAGER->getEnemyList();
	int minLevel = TILEMANAGER->getMinLevel();
	int maxLevel = TILEMANAGER->getMaxLevel();

	Player* enemy = new Enemy;
	enemy->init(enemyList[RND->getInt(enemyList.size())], RND->getFromIntTo(minLevel, maxLevel));
	addAllPlayer(enemy);



	//���� ��ġ
	Player* user = (*TURNMANAGER->getAllPlayer())[0];
	RECT tmp;
	while (true) {
		vector<RECT>* room = TILEMANAGER->getvRoom();
		int index = RND->getInt(room->size());
		RECT roomRECT = RectMake(
			(*room)[index].left * TILEWIDTH, (*room)[index].top * TILEHEIGHT,
			((*room)[index].right - (*room)[index].left) * TILEWIDTH,
			((*room)[index].bottom - (*room)[index].top) * TILEHEIGHT);

		if(IntersectRect(&tmp, &roomRECT, &user->getBody()))
			continue;

		float x = RND->getFromIntTo((*room)[index].left, (*room)[index].right);
		float y = RND->getFromIntTo((*room)[index].top, (*room)[index].bottom);

		enemy->initXY(x, y);
		break;
	}
}

void turnManager::inputFromPlayer()
{
	//(���� �Ҹ�Ǵ�)input�� ������ order++
	if (_allPlayerList[_order]->input() != END_POKEMON_STATE) {
		addInputPlayer(_allPlayerList[_order]);
		_order++;
	}

	//��� Player input�� ������ ���� ������
	if (_order >= _allPlayerList.size())
		_input = false;
}

void turnManager::addAllPlayer(Player * player)
{
	_allPlayerList.push_back(player);
}

void turnManager::addInputPlayer(Player * player)
{
	_inputPlayerList.push_back(player);
}

Player * turnManager::getCurrentPlayer()
{
	if (_inputPlayerList.size())
		return _inputPlayerList[0];

	return nullptr;
}
