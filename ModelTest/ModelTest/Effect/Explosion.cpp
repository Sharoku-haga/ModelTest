/**
* @file		Explosion.cpp
* @brief	Explosionクラス実装
* @author	haga
*/

//-------------------------------------------------------------------------------------------------------------//
//Includes
//-------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "Explosion.h"

//-------------------------------------------------------------------------------------------------------------//
//Unnamed namespace
//-------------------------------------------------------------------------------------------------------------//

namespace
{

const int		AnimeTime = 0;					// アニメーションの間隔
const int		AnimePattern = 3;				// アニメーションのパターン数
const float		AnimeUV = 0.25f;				// アニメーションで変動するUV値

}

//-------------------------------------------------------------------------------------------------------------//
//Public functions
//-------------------------------------------------------------------------------------------------------------//

Explosion::Explosion(D3DXVECTOR3 pos, int texID, int vtxID)
	: Effect(pos,texID,vtxID)
	, m_AnimeTimeCount(0)
	, m_AnimePattern(0)
{
}

Explosion::~Explosion()
{
}

bool Explosion::Control()
{
	if(m_AnimeTimeCount == AnimeTime)
	{
		if(m_AnimePattern == AnimePattern)
		{
			m_IsEnd = true;
		}
		else
		{
			m_AnimePattern++;
			GameLib::Instance().SetVtxUV(m_VtxID, 0.0f + ( AnimeUV * m_AnimePattern ), 0.25f + ( AnimeUV * m_AnimePattern ), 0.0f, 0.25f);

			m_AnimeTimeCount = 0;
		}
	}
	else
	{
		m_AnimeTimeCount++;
	}

	return m_IsEnd;
}

void Explosion::Draw()
{
	Transform3D();
	GameLib::Instance().Draw3DCenterPos(m_TexID, m_VtxID);
}
