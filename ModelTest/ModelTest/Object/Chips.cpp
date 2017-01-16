/**
* @file		Chips.cpp
* @brief	Chipsクラス実装
* @athor	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "../Collision/BoundingSphere.h"
#include "../Effect/EffectManager.h"
#include "Chips.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

Chips::Chips(D3DXVECTOR3	pos, float angle, int xFileID)
	: Object(pos, angle, xFileID)
{
	m_Radius = 1.0f;
	m_Sphere = new BoundingSphere();
	m_Sphere->CreateSphere(m_Radius);
}

Chips::~Chips()
{
	// リソース解放は基底クラスにて行う
}

void Chips::Control()
{
}

void Chips::Draw()
{
	Transform3D();
	GameLib::Instance().DrawXFile(m_XFileID);
	//m_Sphere->Draw();
}

void Chips::InformCollision()
{
	EffectManager::Instance().Create(m_Pos, EffectManager::EXPLOSION);
	m_HasVanished = true;
}

