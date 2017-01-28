/**
* @file		PushOnlyButton.cpp
* @brief	PushOnlyButtonクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "PushOnlyButton.h"

//------------------------------------------------------------------------------------------------------------//
//Unnamed namespace
//------------------------------------------------------------------------------------------------------------//

namespace
{

const BYTE	FadeNormalSpeed = 0x15;					// フェード処理を行う通常スピード

}

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

PushOnlyButton::PushOnlyButton(float width, float height, D3DXVECTOR2 pos, int texID, int vtxID)
	: Button( width, height, pos, texID, vtxID)
	, m_Alpha(0x00)
	, m_IsFadeIn(true)
{
	GameLib::Instance().CreateVtx(vtxID,width,height);
}

PushOnlyButton::~PushOnlyButton()
{
}

void PushOnlyButton::Control()
{
	FadeInOut();
}

void PushOnlyButton::Draw()
{
	DWORD color = D3DCOLOR_ARGB(m_Alpha, 0xff, 0xff, 0xff);
	GameLib::Instance().SetVtxColor(m_VtxID,color);
	GameLib::Instance().DrawXYCenterPos(m_TexID, m_VtxID, m_Pos.x, m_Pos.y);
}

//------------------------------------------------------------------------------------------------------------//
//Private functions
//------------------------------------------------------------------------------------------------------------//

void PushOnlyButton::FadeInOut()
{
	if(m_IsFadeIn)
	{
		m_Alpha += FadeNormalSpeed;
		if(m_Alpha == 0xFF)
		{
			m_IsFadeIn = false;
		}
	}
	else
	{
		m_Alpha -= FadeNormalSpeed;
		if(m_Alpha == 0x00)
		{
			m_IsFadeIn = true;
		}
	}
}
