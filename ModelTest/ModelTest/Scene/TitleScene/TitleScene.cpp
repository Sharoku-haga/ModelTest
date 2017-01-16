/**
* @file		TitleScene.cpp
* @brief	TitleSceneクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "TitleScene.h"
#include "TitleBackground.h"
#include "../../Button/PushOnlyButton.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

TitleScene::TitleScene()
	: m_pBackground(new TitleBackground())
	, m_pButton(nullptr)
	, m_NextScene(Scene::ID::TEST)
	, m_State(TitleScene::STATE::FADE_IN)
{
	/**TextureLoad*/
	m_rGameLib.LoadTex(TitleScene::TEX_ID::TITLE_BACKGROUND,"../Resource/TitleScene/title.png");
	m_rGameLib.LoadTex(TitleScene::TEX_ID::PUSH_BUTTON, "../Resource/TitleScene/PushButton.png");

	/**ボタンのVertex作成*/
	float		buttonWidth = 1024.f;
	float		buttonHeight = 128.f;
	D3DXVECTOR2 buttonPos = { 800.f, 675.f };
	m_pButton = new PushOnlyButton(buttonWidth, buttonHeight, buttonPos, TitleScene::TEX_ID::PUSH_BUTTON, TitleScene::VTX_ID::PUSH_BTN);
}

TitleScene::~TitleScene()
{
	delete m_pButton;
	delete m_pBackground;
	m_rGameLib.ReleaseVtx(true);
	m_rGameLib.ReleaseTex(true);
}

Scene::ID  TitleScene::Control()
{
	switch(m_State)
	{
	case TitleScene::STATE::FADE_IN :
		if(m_pBackground->FadeIn())
		{
			m_State = TitleScene::STATE::WAIT_PUSH_BUTTON;
		}
		break;

	case TitleScene::STATE::WAIT_PUSH_BUTTON:
		m_pButton->Control();
		if(m_rGameLib.Instance().ChecKMouseL() == ON ||
			m_rGameLib.Instance().CheckKey(DIK_Z,Z) == ON)
		{
			m_State = TitleScene::STATE::FADE_OUT;
		}
		break;

	case TitleScene::STATE::FADE_OUT:
		if(m_pBackground->FedeOut())
		{
			m_State = TitleScene::STATE::NEXT_SCENE;
		}
		break;

	case TitleScene::STATE::NEXT_SCENE:
		return m_NextScene;
		break;
	}
	return Scene::ID::TITLE;
}

void TitleScene::Draw()
{
	m_pBackground->Draw();
	if(m_State == TitleScene::STATE::WAIT_PUSH_BUTTON)
	{
		m_pButton->Draw();
	}
}

