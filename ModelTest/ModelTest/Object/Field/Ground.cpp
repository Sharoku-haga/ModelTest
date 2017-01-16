/**
* @file		Ground.cpp
* @brief	Groundクラス実装
* @author	haga
*/

//----------------------------------------------------------------------------------------------------------//
//Includes
//----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "../../CameraController/CameraController.h"
#include "Ground.h"

//----------------------------------------------------------------------------------------------------------//
//Public functions
//----------------------------------------------------------------------------------------------------------//

Ground::Ground(D3DXVECTOR3	pos, float angle, int xFileID)
	: Field(pos, angle, xFileID)
{
	GameLib::Instance().LoadXFile(m_XFileID, "../Resource/Xfile/Ground.x");
}

Ground::~Ground()
{
}

void Ground::Control()
{
}

void Ground::Draw()
{
	Transform3D();
	GameLib::Instance().DrawXFile(m_XFileID);
}

void Ground::InformCollision()
{
}
