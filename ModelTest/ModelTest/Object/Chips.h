/**
* @file		Chips.h
* @brief	Chipsクラスヘッダ
* @athor	haga
*/

#ifndef CHIPS_H
#define CHIPS_H

#include "Object.h"

/**
* チップの袋のクラス
*/
class Chips :public Object
{
public:
	/**
	* コンストラクタ
	* @param pos		位置座標
	* @param angle		角度
	* @param xFileID	XファイルのID
	*/
	Chips(D3DXVECTOR3	pos, float angle, int xFileID);
	virtual ~Chips();

	/**コントロール関数*/
	virtual void Control()override;

	/**描画関数*/
	virtual void Draw()override;

	/**衝突判定処理*/
	virtual void InformCollision()override;

};

#endif	// CHIPS_H
