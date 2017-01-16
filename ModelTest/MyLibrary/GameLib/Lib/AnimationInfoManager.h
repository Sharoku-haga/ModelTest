/**
* @file		AnimationInfoManager.h
* @brief	AnimationInfoManagerクラスヘッダ
* @author	haga
*/
#ifndef ANIMATION_INFO_MANAGER_H
#define ANIMATION_INFO_MANAGER_H

#include <map>

class AnimationInfo;
/**
* AnimationInfoクラスを管理するクラス
*/
class AnimationInfoManager
{
public:
	/**コンストラクタ*/
	AnimationInfoManager();

	/**デストラクタ*/
	~AnimationInfoManager();

	/**
	* アニメーション情報を登録する関数
	* @param[in]	key			アニメ登録キー
	* @param[in]	aniPat		アニメのパターン数
	* @param[in]	interval	アニメーションの時間間隔	
	* @param[in]	intervalTu	アニメーションで変動するtu値
	* @param[in]	intervalTv	アニメーションで変動するtv値
	* @param[in]	isReverse	逆再生モードか、通常モードかを判定
	*/
	void RegisterAnimationInfo(int key, int aniPat, int interval, float intervalTu, float intervalTv, bool isReverse = false);

	/**
	* アニメーションのコントロールを行う関数
	* @param[in]	key			アニメ登録キー
	*/
	void ControlAnime(int key);

	/**
	* アニメの情報をセットする関数
	* @param[in]	key			アニメ登録キー
	* @param[in]	animeNum	アニメ番号
	* @param[in]	minTu		セットするTu最小値
	* @param[in]	maxTu		セットするTu最大値
	* @param[in]	minTv		セットするTv最小値
	* @param[in]	maxTv		セットするTv最大値
	*/
	void SetAnimeInfo(int key,int animeNum, float minTu, float maxTu, float minTv, float maxTv);

	/**
	* アニメーション情報を解放する関数
	* 現在のアニメのminTu値を取得する関数
	* @param[in] key	mapのキー
	* @return minTu値
	*/
	float GetMinTu(int key);

	/**
	* アニメーション情報を解放する関数
	* 現在のアニメのmaxTu値を取得する関数
	* @param[in] key	mapのキー
	* @return maxTu値
	*/
	float GetMaxTu(int key);

	/**
	* アニメーション情報を解放する関数
	* 現在のアニメのminTv値を取得する関数
	* @param[in] key	mapのキー
	* @return minTv値
	*/
	float GetMinTv(int key);

	/**
	* アニメーション情報を解放する関数
	* 現在のアニメのmaxTv値を取得する関数
	* @param[in] key	mapのキー
	* @return maxTv値
	*/
	float GetMaxTv(int key);

	/**
	* アニメーション情報を解放する関数
	* @param[in] key	mapのキー
	*/
	void Release(int key);

	/**全てのアニメーション情報を解放する関数*/
	void ReleaseALL();

private:
	std::map<int, AnimationInfo*> m_animationInfo;			//!< アニメーション情報を格納する変数
};

#endif	// ANIMATION_INFO_MANAGER_H
