/**
* @file		Explosion.h
* @brief	Explosionクラスヘッダ
* @author	haga
*/

#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Effect.h"


/**
* 爆発効果を扱うクラス.
*/
class Explosion :public Effect
{

public:
	/**
	* コンストラクタ
	* @param pos	位置座標
	* @param texID	テクスチャーID
	* @param vtxID	バーテックスID
	*/
	Explosion(D3DXVECTOR3 pos, int texID, int vtxID);
	virtual ~Explosion();

	/**
	* コントロール関数.
	* @return アニメーションが終了してるかどうか
	*/
	virtual bool Control();

	/**描画関数*/ 
	virtual void Draw();

private:
	int		m_AnimeTimeCount;	//!< アニメ時間カウント
	int		m_AnimePattern;		//!< アニメパターン

};

#endif	// EXPLOSION_H
