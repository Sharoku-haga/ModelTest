/**
* @file		TeamLogo.cpp
* @brief	TeamLogoクラス実装
* @author	haga
*/

//-----------------------------------------------------------------------------------------------------------//
//Includes
//-----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLIb.h"
#include "LogoScene.h"
#include "TeamLogo.h"

//-----------------------------------------------------------------------------------------------------------//
//Namespace
//-----------------------------------------------------------------------------------------------------------//

namespace
{

const BYTE	FadeSpeed = 0x05;					// フェード処理を行うスピード
const int	DispTime = 120;						// ロゴを表示する時間。1単位は、60FPS

}

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

// 座標は決め打ち
TeamLogo::TeamLogo()
	: m_Pos({0.0f,0.0f})
	, m_Alpha(0x00)
	, m_State(TeamLogo::STATE::FADE_IN)
	, m_IsFadeEnd(false)
	, m_DispTimeCount(0)
{
	float logoWidth = static_cast<float>(GameLib::Instance().GetWindowWidth());
	float logoHeight = static_cast<float>(GameLib::Instance().GetWindowHeight());
	GameLib::Instance().CreateVtx(LogoScene::VTX_ID::TEAM_LOGO, logoWidth, logoHeight);
}

TeamLogo::~TeamLogo()
{
	// リソース解放はLogoSceneにて行う
}

bool TeamLogo::Control()
{
	switch(m_State)
	{
	case TeamLogo::STATE::FADE_IN:
		m_Alpha += FadeSpeed;
		if(m_Alpha == 0xFF)
		{
			m_State = TeamLogo::STATE::DISPLAY;
		}
		break;

	case TeamLogo::STATE::DISPLAY:
		if(m_DispTimeCount == DispTime)
		{
			m_State = TeamLogo::STATE::FADE_OUT;
		}
		m_DispTimeCount++;
		break;

	case TeamLogo::STATE::FADE_OUT:
		m_Alpha -= FadeSpeed;
		if(m_Alpha == 0x00)
		{
			m_State = TeamLogo::STATE::HIDE;
		}
		break;

	case TeamLogo::STATE::HIDE:
		m_IsFadeEnd = true;
		break;
	}

	return m_IsFadeEnd;
}

void TeamLogo::Draw()
{
	DWORD color = D3DCOLOR_ARGB(m_Alpha, 0xff, 0xff, 0xff);
	GameLib::Instance().SetVtxColor(LogoScene::VTX_ID::TEAM_LOGO,color);
	GameLib::Instance().DrawXY(LogoScene::TEX_ID::LOGO, LogoScene::VTX_ID::TEAM_LOGO,m_Pos.x,m_Pos.y);
}
