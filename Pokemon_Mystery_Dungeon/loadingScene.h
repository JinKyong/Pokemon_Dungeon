#pragma once
#include "Scene.h"

#define LOADINGMAX	1000

class loadingScene : public Scene
{
private:
	dImage* _back;

	int _width;
	int _height;		//�� ũ��
	int _type;			//�� ����
	int _floor;			//�� ��

public:

	int _currentCount;
	bool _create;

	HRESULT init(Player *player);
	void release();
	void update();
	void render();
	void changeScene();

	static DWORD CALLBACK threadFunction(LPVOID lpParameter);
};

