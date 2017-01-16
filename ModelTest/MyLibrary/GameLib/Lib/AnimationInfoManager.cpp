/**
* @file		AnimationInfoManager.cpp
* @brief	AnimationInfoManagerクラス実装
* @author	haga
*/

//-----------------------------------------------------------------------------------------------------------//
//Icludes
//-----------------------------------------------------------------------------------------------------------//

#include "AnimationInfo.h"
#include "AnimationInfoManager.h"

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

AnimationInfoManager::AnimationInfoManager()
{
}

AnimationInfoManager::~AnimationInfoManager()
{
	ReleaseALL();
}

// アニメショーン情報登録する関数
void AnimationInfoManager::RegisterAnimationInfo(int key, int aniPat, 
	int interval, float intervalTu, float intervalTv, bool isReverse)
{
	m_animationInfo[key] = new AnimationInfo(aniPat, interval, intervalTu, intervalTv, isReverse);
}

// アニメ情報を更新する関数
void AnimationInfoManager :: SetAnimeInfo(int key, int animeNum, float minTu, float maxTu, float minTv, float maxTv)
{
	m_animationInfo[key]->SetAnimeInfo(animeNum, minTu, maxTu, minTv, maxTv);
}

float AnimationInfoManager::GetMinTu(int key)
{
	return m_animationInfo[key]->GetMinTu();
}

float AnimationInfoManager::GetMaxTu(int key)
{
	return m_animationInfo[key]->GetMaxTu();
}

float AnimationInfoManager::GetMinTv(int key)
{ 
	return m_animationInfo[key]->GetMinTv(); 
}

float AnimationInfoManager::GetMaxTv(int key)
{ 
	return m_animationInfo[key]->GetMaxTv(); 
}

// アニメーション情報をコントロール関数
void AnimationInfoManager::ControlAnime(int key)
{
	m_animationInfo[key]->ControlAnime();
}


// アニメーション情報を解放する関数
void AnimationInfoManager::Release(int key)
{
	m_animationInfo[key]->Release();
	m_animationInfo.erase(key);
}

// 全てのアニメーション情報を解放する関数
void AnimationInfoManager::ReleaseALL()
{
	m_animationInfo.clear();
}
