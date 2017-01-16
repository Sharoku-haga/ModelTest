/**
* @file		CameraController.cpp
* @brief	CameraControllerクラス実装
* @author	haga
*/

//-----------------------------------------------------------------------------------------------------------//
//Includes
//-----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "Camera/Camera.h"
#include "CameraController.h"

//-----------------------------------------------------------------------------------------------------------//
//Namespace
//-----------------------------------------------------------------------------------------------------------//

namespace
{

const float		CameraSpeed  = 3.0f;					// カメラスピード
const float		ZoomSpeed	 = 3.0f;					// ズームスピード
const float		RollingSpeed = 10.f;					// 回転スピード

}

//-----------------------------------------------------------------------------------------------------------//
//Pubilc functions
//-----------------------------------------------------------------------------------------------------------//

CameraController::CameraController()
	: m_pCamera(new Camera(GameLib::Instance().GetDevice()))
	, m_vEyePt({0.0f,10.f,-10.f})
	, m_OldVEyePt({ 0.0f, 10.f, -10.f })
	, m_vLookPt({1.0f,0.0f,1.0f})
	, m_ZoomAngle(45.f)
{
	float winWidth = static_cast<float>( GameLib::Instance().GetWindowWidth() );
	float winHeight = static_cast<float>( GameLib::Instance().GetWindowHeight() );
	m_pCamera->InitWindowSize(winWidth, winHeight);
}

CameraController::~CameraController()
{
	delete m_pCamera;
}

void CameraController::Control()
{
	// Y軸移動コントロールキー
	if(GameLib::Instance().CheckKey(DIK_W,W) == ON)
	{
		m_vEyePt.y += CameraSpeed;
		m_vLookPt.y += CameraSpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_S,S) == ON)
	{
		m_vEyePt.y -= CameraSpeed;
		m_vLookPt.y -= CameraSpeed;
	}

	// Z軸移動コントロールキー
	if(GameLib::Instance().CheckKey(DIK_UP, UP) == ON)
	{
		m_vEyePt.z += CameraSpeed;
		m_vLookPt.z += CameraSpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_DOWN, DOWN) == ON)
	{
		m_vEyePt.z -= CameraSpeed;
		m_vLookPt.z -= CameraSpeed;
	}

	// X軸移動コントロールキー
	if(GameLib::Instance().CheckKey(DIK_RIGHT, RIGHT) == ON)
	{
		m_vEyePt.x += CameraSpeed;
		m_vLookPt.x += CameraSpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_LEFT, LEFT) == ON)
	{
		m_vEyePt.x -= CameraSpeed;
		m_vLookPt.x -= CameraSpeed;
	}

	// ズームコントロール
	if(GameLib::Instance().CheckKey(DIK_Z, Z) == ON && m_ZoomAngle >= 0.0f)
	{
		m_ZoomAngle -= ZoomSpeed;
	}

	if(GameLib::Instance().CheckKey(DIK_X, X) == ON && m_ZoomAngle < 90.f)
	{
		m_ZoomAngle += ZoomSpeed;
	}
}

void CameraController::Rotate()
{
	D3DXMATRIX		matRotation; // 回転行列

	//上回転
	if(GameLib::Instance().CheckKey(DIK_W, W) == ON)
	{
		D3DXMatrixRotationX(&matRotation, D3DXToRadian(RollingSpeed));
		matRotation._41 = 0.0f;
		matRotation._42 = 0.0f;
		matRotation._43 = 0.0f;
		D3DXVECTOR3 pos = m_vEyePt - m_vLookPt;
		D3DXVec3TransformCoord(&pos, &pos, &matRotation);
		m_vEyePt = pos + m_vLookPt;
		
	}

	// 下回転
	if(GameLib::Instance().CheckKey(DIK_S, S) == ON)
	{
		D3DXMatrixRotationX(&matRotation, D3DXToRadian(-RollingSpeed));
		matRotation._41 = 0.0f;
		matRotation._42 = 0.0f;
		matRotation._43 = 0.0f;
		D3DXVECTOR3 pos = m_vEyePt - m_vLookPt;
		D3DXVec3TransformCoord(&pos, &pos, &matRotation);
		m_vEyePt = pos + m_vLookPt;
	}

	// 右回転
	if(GameLib::Instance().CheckKey(DIK_D, D) == ON)
	{
		D3DXMatrixRotationY(&matRotation, D3DXToRadian(-RollingSpeed));
		matRotation._41 = 0.0f;
		matRotation._42 = 0.0f;
		matRotation._43 = 0.0f;
		D3DXVECTOR3 pos = m_vEyePt - m_vLookPt;
		D3DXVec3TransformCoord(&pos, &pos, &matRotation);
		m_vEyePt = pos + m_vLookPt;
	}

	// 左回転
	if(GameLib::Instance().CheckKey(DIK_A, A) == ON)
	{
		D3DXMatrixRotationY(&matRotation, D3DXToRadian(RollingSpeed));
		matRotation._41 = 0.0f;
		matRotation._42 = 0.0f;
		matRotation._43 = 0.0f;
		D3DXVECTOR3 pos = m_vEyePt - m_vLookPt;
		D3DXVec3TransformCoord(&pos, &pos, &matRotation);
		m_vEyePt = pos + m_vLookPt;
	}
}

void CameraController::TransformView()
{
	m_pCamera->LookInCamera(&m_vEyePt, &m_vLookPt, m_ZoomAngle);
}

void CameraController::SetVLookPt(const D3DXVECTOR3& objPos)
{
	m_vLookPt = objPos;
}

void CameraController::SetOldVLookPt(const D3DXVECTOR3& objPos)
{
	m_OldVEyePt = objPos;
}

void CameraController::SetVEyePt(const D3DXVECTOR3& objPos)
{
	m_vEyePt = objPos;
}

void CameraController::AddVEyePt(const D3DXVECTOR3& objSpeed)
{
	m_vEyePt += objSpeed;
	m_OldVEyePt += objSpeed;
}

void CameraController::Init()
{
	D3DXMATRIX		matRotation;						// 回転行列
	D3DXMatrixRotationY(&matRotation, D3DXToRadian(0.0f));
	D3DXVec3TransformCoord(&m_vLookPt, &m_vLookPt, &matRotation);
	m_vEyePt = m_OldVEyePt;
	m_ZoomAngle = 45.f;
}

