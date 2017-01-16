/**
* @file		Field.h
* @brief	Fieldクラスヘッダ
* @author	haga
*/

#ifndef FIELD_H
#define FIELD_H

#include <d3dx9.h>
#include "../Object.h"

/**
* フィールドの基底クラス.
*/
class Field : public Object
{

public:
	/**
	* コンストラクタ
	* @param pos		位置座標
	* @param angle		角度
	* @param xFileID	XファイルのID
	*/
	Field(D3DXVECTOR3	pos, float angle, int xFileID);
	virtual ~Field();
	
	/***/
	virtual void Control() = 0;

	/***/
	virtual void Draw() = 0;

	/**衝突判定処理*/
	virtual void InformCollision() = 0;

};

#endif	// FIELD_H
