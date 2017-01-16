/**
* @file		EffectManager.cpp
* @brief	EffectManagerクラス実装
* @author	haga
*/

//-------------------------------------------------------------------------------------------------------------//
//Includes
//-------------------------------------------------------------------------------------------------------------//

#include "../Scene/TestScene/TestScene.h"
#include "Effect.h"
#include "EffectManager.h"
#include "Explosion.h"

//-------------------------------------------------------------------------------------------------------------//
//Public functions
//-------------------------------------------------------------------------------------------------------------//

void EffectManager::Create(const D3DXVECTOR3& rPos, EffectManager::EFFECT_TYPE type)
{
	switch(type)
	{
	case EffectManager::EXPLOSION:
		m_Effect.emplace_back(new Explosion(rPos, TestScene::EXPLOSION_TEX, TestScene::EXPLOSION_VTX));
		break;
	}
}


void EffectManager::Control()
{
	if(m_Effect.size() > 0)
	{
		for(auto itr = m_Effect.begin(); itr != m_Effect.end();)
		{
			if((*itr)->Control())
			{
				delete ( *itr);
				itr = m_Effect.erase(itr);
			}
			else
			{
				++itr;
			}
		}
	}
}

void EffectManager::Draw()
{
	if(m_Effect.size() > 0)
	{
		for(auto i : m_Effect)
		{
			i->Draw();
		}
	}
}

EffectManager::~EffectManager()
{
	for(auto i : m_Effect)
	{
		delete i;
	}
}

//-- ----------------------------------------------------------------------------------------------------------//
//Private functions
//------------------------------------------------------------------------------------------------------------//

EffectManager::EffectManager()
{
}

