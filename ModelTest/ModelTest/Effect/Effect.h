/**
* @file		Effect.h
* @brief	Effectクラスヘッダ
* @author	haga
*/

#ifndef EFFECT_H
#define EFFECT_H

#include <d3dx9.h>

/**
* エフェクト(効果)の基底クラス
*/
class Effect
{

public:
	/**
	* コンストラクタ
	* @param pos	位置座標
	* @param texID	テクスチャーID
	* @param vtxID	バーテックスID
	*/
	Effect(D3DXVECTOR3 pos, int texID, int vtxID);
	virtual ~Effect();

	/**
	* コントロール関数.
	* @return アニメーションが終了してるかどうか
	*/
	virtual bool Control() = 0;

	/**描画関数*/
	virtual void Draw() = 0;

protected:
	D3DXVECTOR3		m_Pos;			//!< 位置座標
	D3DXMATRIX		m_MatWorld;		//!< ワールド座標行列
	int				m_TexID;		//!< テクスチャーID
	int				m_VtxID;		//!< バーテックスiD
	bool			m_IsEnd;		//!< アニメーションが終了してるかどうか

	/**3D座標変換*/
	void Transform3D();

	/**ビルボード処理*/
	void ChangeBillboarding();

};

#endif	// EFFECT_H