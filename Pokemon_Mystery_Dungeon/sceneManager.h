#pragma once
#include "singletonBase.h"
#include <string>
#include <map>

class Player;
class Scene;

class sceneManager : public singletonBase<sceneManager>
{
private:
	typedef map<string, Scene*>			  mapSceneList;
	typedef map<string, Scene*>::iterator mapSceneIter;

private:
	static Player* _player;
	static Scene* _currentScene;
	int _sceneCount;

	mapSceneList _mSceneList;

	sceneManager() {};
	friend singletonBase<sceneManager>;

public:
	HRESULT init();
	HRESULT init(Player* player);
	void release();
	void update();
	void render();

	Scene* addScene(string sceneName, Scene* scene);
	HRESULT changeScene(string sceneName);

	Scene* getCurrentScene() { return _currentScene; }

	void setSceneCount(int SceneCount) { _sceneCount = SceneCount; }
	int getSceneCount() { return _sceneCount; }
};