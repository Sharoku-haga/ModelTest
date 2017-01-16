/**
* @file		FieldManager.cpp
* @brief	FieldManagerクラス実装
* @author	haga
*/

//--------------------------------------------------------------------------------------------------------------//
//Includes
//--------------------------------------------------------------------------------------------------------------//

#include "../../Scene/TestScene/TestScene.h"
#include "Field.h"
#include "Ground.h"
#include "FieldManager.h"

//-------------------------------------------------------------------------------------------------------------//
//Public functions
//-------------------------------------------------------------------------------------------------------------//

FieldManager::FieldManager()
{
	m_pField = new Ground(D3DXVECTOR3(0.0f, 0.0f, 0.0f), 0.0f, TestScene::XFILE_ID::GROUND);
}

FieldManager::~FieldManager()
{
	delete m_pField;
}

void FieldManager::Control()
{
	m_pField->Control();
}

void FieldManager::Draw()
{
	m_pField->Draw();
}
