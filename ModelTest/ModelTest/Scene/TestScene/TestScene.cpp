/**
* @file		TestScene.cpp
* @brief	TestSceneクラス実装
* @author	haga
*/

//-----------------------------------------------------------------------------------------------------------//
//Includes
//-----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "Font/Font.h"
#include "../../Object/ObjectManager.h"
#include "../../Object/Field/FieldManager.h"
#include "TestScene.h"
#include "../../CameraController/CameraController.h"
#include "../../Effect/EffectManager.h"

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

TestScene::TestScene()
	: m_pObjectManager(new ObjectManager())
	, m_pFieldManager(new FieldManager())
	, m_CourrentMode(MODE::NOMAL_MODE)
{
	GameLib::Instance().LoadTex(TestScene::EXPLOSION_TEX,"../Resource/TestScene/Effect.dds");
	GameLib::Instance().CreateVtx(TestScene::EXPLOSION_VTX, 10.f, 10.f);
	GameLib::Instance().SetVtxUV(TestScene::EXPLOSION_VTX, 0.0f, 0.25f, 0.0f, 0.25f);
}

TestScene::~TestScene()
{
	delete m_pFieldManager;
	delete m_pObjectManager;
	m_rGameLib.ReleaseXFile(true);
}

Scene::ID TestScene::Control()
{
	m_pFieldManager->Draw();
	switch(m_CourrentMode)
	{
	case MODE::NOMAL_MODE :
		m_pObjectManager->Control();
		if(m_rGameLib.CheckKey(DIK_C, C) == ON)
		{
			m_CourrentMode = MODE::CAMERA_MODE;
		}

		if(m_rGameLib.CheckKey(DIK_B, B) == ON)
		{
			m_CourrentMode = MODE::ROTATION_MODE;
		}
		break;

	case MODE::CAMERA_MODE :
		CameraController::Instance().Control();
		if(m_rGameLib.CheckKey(DIK_V, V) == ON)
		{
			m_CourrentMode = MODE::NOMAL_MODE;
			CameraController::Instance().Init();
		}

		if(m_rGameLib.CheckKey(DIK_B, B) == ON)
		{
			m_CourrentMode = MODE::ROTATION_MODE;
		}
		break;

	case MODE::ROTATION_MODE :
		CameraController::Instance().Rotate();
		if(m_rGameLib.CheckKey(DIK_C, C) == ON)
		{
			m_CourrentMode = MODE::CAMERA_MODE;
		}

		if(m_rGameLib.CheckKey(DIK_V, V) == ON)
		{
			m_CourrentMode = MODE::NOMAL_MODE;
			CameraController::Instance().Init();
		}
	}

	EffectManager::Instance().Control();

	return Scene::ID::TEST;
}

void TestScene::Draw()
{
	//m_rGameLib.GetDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_rGameLib.GetDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);
	m_rGameLib.GetDevice()->SetRenderState(D3DRS_AMBIENT, 0x00555555);
	m_rGameLib.GetDevice()->SetRenderState(D3DRS_SPECULARENABLE, TRUE);

	m_rGameLib.SetFVF(USER_VERTEX_FVF);
	m_pFieldManager->Draw();
	m_pObjectManager->Draw();
	EffectManager::Instance().Draw();

	m_rGameLib.SetFVF(DIRECT3DFVF_CUSTOMVERTEX);
	switch(m_CourrentMode)
	{
	case MODE::NOMAL_MODE:
		m_rGameLib.DrawDebugFont("通常モード", 0.0f, 0.0f);
		break;

	case MODE::CAMERA_MODE:
		m_rGameLib.DrawDebugFont("カメラモード", 0.0f, 0.0f);
		break;

	case MODE::ROTATION_MODE:
		m_rGameLib.DrawDebugFont("回転モード", 0.0f, 0.0f);
		break;
	}
}
