/**
* @file		Player.cpp
* @brief	Playerクラス実装
* @author	haga
*/

//-------------------------------------------------------------------------------------------------------------//
//Includes
//-------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "Font/Font.h"
#include "../CameraController/CameraController.h"
#include "../Collision/BoundingSphere.h"
#include "Player.h"

//------------------------------------------------------------------------------------------------------------//
//Unnamed namespace
//------------------------------------------------------------------------------------------------------------//

namespace
{

const float		PlaySpeed		 = 0.5f;		// プレイヤーが動くスピード
const float		RollingSpeed	 = 5.0f;		// 回転スピード

}

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

Player::Player(const D3DXVECTOR3& pos, float angle, int xFileID)
	: Object(pos, angle, xFileID)
	, m_pFont(new Font(GameLib::Instance().GetDevice(),40,30))
	, m_IsCollision(false)
{
	GameLib::Instance().LoadXFile(m_XFileID, "../Resource/Xfile/Human.x");
	m_Radius = 1.0f;
	m_Sphere = new BoundingSphere();
	m_Sphere->CreateSphere(m_Radius);
}

Player::~Player()
{
	delete m_pFont;
	//delete m_Sphere;は基底クラスで行う
}

void Player::Control()
{
	ControlKey();
	CameraController::Instance().SetVLookPt(m_Pos);
}

void Player::Draw()
{
	Transform3D();
	GameLib::Instance().DrawXFile(m_XFileID);
	if(m_IsCollision)
	{
		m_pFont->Draw("人が何かにあたりました", D3DXVECTOR2(400.f, 450.f));
		m_IsCollision = false;

	}
	//m_Sphere->Draw();
}

void Player::InformCollision()
{
	m_IsCollision = true;
}

//-------------------------------------------------------------------------------------------------------------//
//Private functions
//-------------------------------------------------------------------------------------------------------------//

void Player::ControlKey()
{
	D3DXVECTOR3 vecAxisX = { 1.0f, 0.0f, 0.0f };
	D3DXVECTOR3 vecAxisZ = { 0.0f, 0.0f, 1.0f };
	D3DXVECTOR3 cameraSpeed = {0.0f,0.0f,0.0f};

	// 向きのコントロールキー
	if(GameLib::Instance().CheckKey(DIK_D, D) == ON)
	{
		m_Angle += RollingSpeed;
		if(m_Angle > 360.f)
		{
			m_Angle -= 360.f;
		}
	}

	if(GameLib::Instance().CheckKey(DIK_A, A) == ON)
	{
		m_Angle -= RollingSpeed;
		if(m_Angle < -360.f)
		{
			m_Angle += 360.f;
		}
	}

	D3DXMATRIX		matRotation;						// 回転行列
	D3DXMatrixRotationY(&matRotation, D3DXToRadian(m_Angle));
	D3DXVec3TransformCoord(&vecAxisX, &vecAxisX, &matRotation);
	D3DXVec3TransformCoord(&vecAxisZ, &vecAxisZ, &matRotation);

	// 移動コントロールキー
	if(GameLib::Instance().CheckKey(DIK_UP,UP) == ON)
	{
		m_Pos += vecAxisZ * PlaySpeed;
		cameraSpeed += vecAxisZ * PlaySpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_DOWN,DOWN) == ON)
	{
		m_Pos -= vecAxisZ * PlaySpeed;
		cameraSpeed -= vecAxisZ * PlaySpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_RIGHT,RIGHT) == ON)
	{
		m_Pos += vecAxisX * PlaySpeed;
		cameraSpeed += vecAxisX * PlaySpeed;;
	}

	if(GameLib::Instance().CheckKey(DIK_LEFT,LEFT) == ON)
	{
		m_Pos -= vecAxisX * PlaySpeed;
		cameraSpeed -= vecAxisX * PlaySpeed;;
	}

	CameraController::Instance().AddVEyePt(cameraSpeed);
}
