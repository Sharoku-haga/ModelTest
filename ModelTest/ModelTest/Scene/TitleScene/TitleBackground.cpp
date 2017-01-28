/**
* @file		TitleBackground.cpp
* @brief	TitlrBackgroundクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "TitleScene.h"
#include "TitleBackground.h"

//------------------------------------------------------------------------------------------------------------//
//Unnamed namespace
//------------------------------------------------------------------------------------------------------------//

namespace
{

const BYTE	fedeSpeed = 0x05;				// フェードインアウトのスピード

}

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

TitleBackground::TitleBackground()
	: m_Pos({0.0f,0.0f})
	, m_Alpha(0x00)
	, m_IsFadeInEnd(false)
	, m_IsFadeOutEnd(false)
{
	GameLib::Instance().CreateVtx(TitleScene::VTX_ID::BACKGROUND,1600.f,900.f);
}

TitleBackground::~TitleBackground()
{
	// リソースはTitleSceneにて解放
}

bool TitleBackground::FadeIn()
{
	if(m_Alpha == 0xFF)
	{
		m_IsFadeInEnd = true;
	}
	else
	{
		m_Alpha += fedeSpeed;
	}
	return m_IsFadeInEnd;
}

bool TitleBackground::FedeOut()
{
	if(m_Alpha == 0x00)
	{
		m_IsFadeOutEnd = true;
	}
	else
	{
		m_Alpha -= fedeSpeed;
	}
	return m_IsFadeOutEnd;
}

void TitleBackground::Draw()
{
	DWORD color = D3DCOLOR_ARGB(m_Alpha, 0xff, 0xff, 0xff);
	GameLib::Instance().SetVtxColor(TitleScene::VTX_ID::BACKGROUND,color);
	GameLib::Instance().DrawXY(TitleScene::TEX_ID::TITLE_BACKGROUND,TitleScene::VTX_ID::BACKGROUND,m_Pos.x,m_Pos.y);
}
