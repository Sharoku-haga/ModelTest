/**
* @file		ObjectManager.cpp
* @brief	ObjectManagerクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "../Scene/TestScene/TestScene.h"
#include "Object.h"
#include "Player.h"
#include "Chips.h"
#include "../Collision/Collision.h"
#include "ObjectManager.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

ObjectManager::ObjectManager()
	: m_pCollision(new Collision())
{
	GameLib::Instance().LoadXFile(TestScene::XFILE_ID::CHIPS, "../Resource/Xfile/Chips.x");
	m_pObject.emplace_back(new Player(D3DXVECTOR3(0.0f,1.2f,0.0f),0.0f,TestScene::XFILE_ID::PLAYER));
	m_pObject.emplace_back(new Chips(D3DXVECTOR3(10.0f, 1.2f, 20.0f), 0.0f, TestScene::XFILE_ID::CHIPS));
	m_pObject.emplace_back(new Chips(D3DXVECTOR3(30.0f, 1.2f, 40.0f), 0.0f, TestScene::XFILE_ID::CHIPS));
}

ObjectManager::~ObjectManager()
{
	for(auto& obj: m_pObject)
	{
		delete obj;
	}
	delete m_pCollision;
}

void ObjectManager::Control()
{
	m_pCollision->CheckCollision();

	for(auto itr = m_pObject.begin(); itr != m_pObject.end();)
	{
		if((*itr)->CheckDisappearance())
		{
			delete (*itr);
			itr = m_pObject.erase(itr);
			continue;
		}
		++itr;
	}

	for(auto itr = m_pObject.begin(); itr != m_pObject.end(); ++itr)
	{
		(*itr)->Control();
	}

	m_pCollision->SetObject(m_pObject);
}

void ObjectManager::Draw()
{
	for(auto itr = m_pObject.begin(); itr != m_pObject.end(); ++itr)
	{
		(*itr)->Draw();
	}
}
