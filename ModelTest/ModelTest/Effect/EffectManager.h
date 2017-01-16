/**
* @file		EffectManager.h
* @brief	EffectManagerクラスヘッダ
* @author	haga
*/

#ifndef EFFECT_MANAGER_H
#define EFFECT_MANAGER_H

#include <d3dx9.h>
#include <list>

class Effect;

/**
* エフェクトを管理するクラス
*/
class EffectManager
{

public:
	/**エフェクトの種類*/
	enum EFFECT_TYPE
	{
		EXPLOSION,			//!< 爆発
	};

	/**
	* 実体を取得する関数.
	* Singletonパターン
	* @return EffectManagerクラスのインスタンス
	*/
	static EffectManager& Instance()
	{
		static EffectManager effectManager;
		return effectManager;
	}
	/**
	* エフェクト作成する関数
	* @param rPos	位置座標
	* @param type	作成するエフェクトのタイプ
	*/
	void Create(const D3DXVECTOR3& rPos, EFFECT_TYPE type);

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

	~EffectManager();

private:
	std::list<Effect*>	m_Effect;		//!< Effectクラスのインスタンスへのポインタの動的配列

	/**Singletonパターンの為private*/
	EffectManager();

};

#endif
