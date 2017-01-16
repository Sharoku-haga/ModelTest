/**
* @file		Player.h
* @brief	Playerクラスヘッダ
* @author	haga
*/

#ifndef PLYER_H
#define PLYER_H

#include <d3dx9.h>
#include "Object.h"

class BoundingSphere;
class Font;

/**
* プレイヤーのクラス
*/
class Player :public Object
{

public:
	/**
	* コンストラクタ
	* @param pos		位置座標
	* @param angle		角度
	* @param xFileID	XファイルのID
	*/
	Player(const D3DXVECTOR3&	pos, float angle, int xFileID);

	/**デストラクタ*/
	virtual ~Player();

	/**コントロール関数*/
	virtual void Control()override;

	/**描画関数*/
	virtual void Draw()override;

	/**衝突判定処理*/
	virtual void InformCollision()override;

private:
	Font*			m_pFont;				//!< Fontクラスのインスタンスへのポインタ
	bool			m_IsCollision;			//!< 衝突したかどうかのフラグ

	/**キー操作関連*/
	void ControlKey();

};

#endif	// PLYER_H
