#include "stdafx.h"
#include "EffectManager.h"
#include "EF_Lightning.h"
#include "EF_FireBlast.h"
#include "EF_Gust.h"
#include "EF_RockSlide.h"

HRESULT EffectManager::init()
{
	registerEffect(EF_FIREBLAST, new EF_FireBlast);
	registerEffect(EF_GUST, new EF_Gust);
	registerEffect(EF_LIGHTNING, new EF_Lightning);
	registerEffect(EF_ROCKSLIDE, new EF_RockSlide);
	return S_OK;
}

void EffectManager::release()
{
}

void EffectManager::update()
{
	for (_viEffect = _vEffect.begin(); _viEffect != _vEffect.end();)
	{
		if ((*_viEffect)->getOff())
		{
			//SAFE_DELETE(*_viEffect); // 에러나면 순서만 바꾸기	//이거 활성화시키니 새로 이펙트가 나오면 터짐
			_viEffect = _vEffect.erase(_viEffect);
		}
		else ++_viEffect;
	}
}

void EffectManager::render()
{
	for (_viEffect = _vEffect.begin(); _viEffect != _vEffect.end(); ++_viEffect)
	{
		(*_viEffect)->render();
	}
}

Effect * EffectManager::registerEffect(int effectNum, Effect * effect)
{
	if (!effect) return nullptr;

	_mEffectList.insert(make_pair(effectNum, effect));

	return effect;
}

HRESULT EffectManager::addEffect(float x, float y, int effect)
{
	_miEffectList = _mEffectList.find(effect);

	if (_miEffectList != _mEffectList.end())
	{
		_miEffectList->second->init(x, y);
		_vEffect.push_back(_miEffectList->second);

		return S_OK;
	}

	return E_NOTIMPL;
}
