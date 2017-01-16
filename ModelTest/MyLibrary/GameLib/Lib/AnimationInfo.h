/**
* @file		AnimationInfo.h
* @brief	AnimationInfoクラスヘッダ
* @author	haga
*/
#ifndef ANIMATION_INFO_H
#define ANIMATION_INFO_H

/**
* アニメーションの情報を管理するクラス
*/
class AnimationInfo
{
public:
	/**
	* コンストラクタ
	* @param[in]	aniPat		アニメのパターン数
	* @param[in]	interval	アニメーションの時間間隔	
	* @param[in]	intervalTu	アニメーションで変動するtu値
	* @param[in]	intervalTv	アニメーションで変動するtv値
	* @param[in]	isReverse	逆再生モードか、通常モードかを判定
	*/
	AnimationInfo(int aniPat,int interval,float intevalTu,float intevalTv,bool isReverse = false);

	/**デストラクタ*/
	~AnimationInfo();

	/**アニメのコントロール関数*/
	void ControlAnime();

	/**
	* アニメの情報をセットする関数
	* @param[in] animeNum	アニメ番号
	* @param[in] minTu		セットするTu最小値
	* @param[in] maxTu		セットするTu最大値
	* @param[in] minTv      セットするTv最小値
	* @param[in] maxTv		セットするTv最大値
	*/
	void SetAnimeInfo(int animeNum, float minTu, float maxTu, float minTv, float maxTv);

	void Release();

	/**
	* 現在のアニメのminTu値を取得する関数 
	* @return minTu値 
	*/
	inline float GetMinTu(){ return m_animeInfo[m_currentAnimeNum].minTu; }

	/**
	* 現在のアニメのminTu値を取得する関数
	* @return maxTu値
	*/
	inline float GetMaxTu(){ return m_animeInfo[m_currentAnimeNum].maxTu; }

	/**
	* 現在のアニメのminTu値を取得する関数
	* @return minTv値
	*/
	inline float GetMinTv(){ return m_animeInfo[m_currentAnimeNum].minTv; }

	/**
	* 現在のアニメのminTu値を取得する関数
	* @return maxTv値
	*/
	inline float GetMaxTv(){ return m_animeInfo[m_currentAnimeNum].maxTu; }

private:
	/**アニメ情報の構造体*/
	struct AnimeInfo
	{
		float		minTu;				//!< 最小tu値
		float		minTv;				//!< 最小tv値
		float       maxTu;				//!< 最大tu値
		float       maxTv;				//!< 最大tv値
	};

	AnimeInfo*	m_animeInfo;		//!< アニメ情報を格納する変数(動的に確保する)
	int			m_animePattern;		//!< アニメパターン数
	int			m_interval;			//!< アニメ間隔(fr)
	int			m_currentInterval;	//!< 現在間隔
	int         m_currentAnimeNum;	//!< 現在のアニメ番号
	bool		m_isReverseMode;	//!< アニメ再生方式(trueならﾘﾊﾞｰｽ,falseならノーマル)
	bool		m_hasReversed;		//!< アニメを逆再生しているかどうか(アニメ再生方式がﾘﾊﾞｰｽの場合)

	/**リバースモードにおけるコントロール関数*/
	void ControlReverseMode();

	/**ノーマルモードにおけるコントロール関数*/
	void ControlNormalMode();
		
};

#endif // ANIMATION_INFO_H

