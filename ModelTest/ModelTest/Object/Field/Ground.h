/**
* @file		Ground.h
* @brief	Groundクラスヘッダ
* @author	haga
*/

#ifndef GROUND_H
#define GROUND_H

#include "Field.h"

/**
* Fieldの地面を管理するクラス.
*/
class Ground : public Field
{

public:
	/**
	* コンストラクタ
	* @param pos		位置座標
	* @param angle		角度
	* @param xFileID	XファイルのID
	*/
	Ground(D3DXVECTOR3	pos, float angle, int xFileID);
	virtual ~Ground();

	/**コントロール関数*/
	virtual void Control()override;

	/**描画関数*/
	virtual void Draw()override;

	/**衝突判定処理*/
	virtual void InformCollision()override;

};

#endif	// GROUND_H
