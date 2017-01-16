/**
* @file		Object.cpp
* @brief	Objectクラス実装
* @author	haga
*/

//-----------------------------------------------------------------------------------------------------------//
//Includes
//-----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "../CameraController/CameraController.h"
#include "../Collision/BoundingSphere.h"
#include "Object.h"

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

Object::Object(D3DXVECTOR3	pos, float angle, int xFileID)
	: m_rGameLib(GameLib::Instance())
	, m_Sphere(nullptr)
	, m_Pos(pos)
	, m_Angle(angle)
	, m_XFileID(xFileID)
	, m_Radius(0.0f)
	, m_HasVanished(false)
{
}

Object::~Object()
{
	delete m_Sphere;
}

//-----------------------------------------------------------------------------------------------------------//
//Private functions
//-----------------------------------------------------------------------------------------------------------//

void Object::Transform3D()
{
	D3DXMATRIX		matPosition;							// 移動用行列
	D3DXMatrixIdentity(&m_MatWorld);						// 単位行列
	D3DXMatrixTranslation(&matPosition, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMatrixRotationY(&m_MatWorld, D3DXToRadian(m_Angle));
	D3DXMatrixMultiply(&m_MatWorld, &m_MatWorld, &matPosition);
	m_rGameLib.GetDevice()->SetTransform(D3DTS_WORLD, &m_MatWorld);

	CameraController::Instance().TransformView();
}

