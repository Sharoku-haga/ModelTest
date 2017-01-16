/**
* @file		AnimationInfo.cpp
* @brief	AnimationInfoクラス実装
* @author	haga
*/

//----------------------------------------------------------------------------------------------------------//
//Includes
//----------------------------------------------------------------------------------------------------------//

#include "AnimationInfo.h"

//---------------------------------------------------------------------------------------------------------//
//Public functions
//---------------------------------------------------------------------------------------------------------//

AnimationInfo::AnimationInfo(int aniPat, int interval, float intervalTu, float intervalTv, bool isReverse)
	: m_animePattern(aniPat)
	, m_interval(interval)
	, m_currentInterval(0)
	, m_currentAnimeNum(0)
	, m_isReverseMode(isReverse)
	, m_hasReversed(false)
{
	m_animeInfo = new AnimeInfo[m_animePattern];

	int countNumTu = 0;				// Tu値を増やした回数をカウントする数
	int countNumTv = 0;				// Tv値を増やした回数をカウントする数

	for(int i = 0; i < m_animePattern; i++)
	{
		if(intervalTv != 1.0f && intervalTu == 1.0f)
		{
			countNumTu = 0;
			countNumTv++;
		}

		m_animeInfo[i].minTu = 0.0f + ( intervalTu *  countNumTu );
		m_animeInfo[i].maxTu = intervalTu + ( intervalTu *  countNumTu );
		m_animeInfo[i].minTv = 0.0f + ( intervalTv * countNumTv );
		m_animeInfo[i].maxTv = intervalTv + ( intervalTv * countNumTv );

		countNumTu++;
	}
}

AnimationInfo::~AnimationInfo()
{
	Release();
}

/**アニメのコントロール関数*/
void AnimationInfo::ControlAnime()
{
	if(m_isReverseMode)
	{
		ControlReverseMode();
	}
	else
	{
		ControlNormalMode();
	}
}

// アニメ情報を設定する関数
void AnimationInfo::SetAnimeInfo(int animeNum, float minTu, float maxTu, float minTv, float maxTv)
{
	m_animeInfo[( animeNum - 1 )].minTu = minTu;
	m_animeInfo[( animeNum - 1 )].maxTu = maxTu;
	m_animeInfo[( animeNum - 1 )].minTv = minTv;
	m_animeInfo[( animeNum - 1 )].maxTv = maxTv;
}

// 解放関数
void AnimationInfo::Release()
{
	delete[] m_animeInfo;
	m_animeInfo = nullptr;
}

//----------------------------------------------------------------------------------------------------------//
//Private functions
//----------------------------------------------------------------------------------------------------------//

void AnimationInfo::ControlReverseMode()
{
	if(m_currentInterval != m_interval)
	{
		m_currentInterval++;
		return;
	}
	else
	{
		if(m_hasReversed)
		{
			m_currentAnimeNum--;
		}
		else
		{
			m_currentAnimeNum++;
		}

		if(m_currentAnimeNum == 0)
		{
			m_hasReversed = false;
		}
		else if(m_currentAnimeNum == ( m_animePattern - 1 ))
		{
			m_hasReversed = true;
		}

		m_currentInterval = 0;
	}
}

void AnimationInfo::ControlNormalMode()
{
	if(m_currentInterval != m_interval)
	{
		m_currentInterval++;
		return;
	}
	else
	{
		if(m_currentAnimeNum == ( m_animePattern - 1 ))
		{
			m_currentAnimeNum = 0;
		}
		else
		{
			m_currentAnimeNum++;
		}
		m_currentInterval = 0;
	}
}

