/**
* @file		Object.h
* @brief	Objectクラスヘッダ
* @author	haga
*/ 

#ifndef OBJECT_H
#define OBJECT_H

#include <d3dx9.h>

class GameLib;
class BoundingSphere;

/**
* プログラム内で表示する3Dオブジェクトの基底クラス.
*/

class Object
{

public:
	/**
	* コンストラクタ
	* @param pos		位置座標
	* @param angle		角度
	* @param xFileID	XファイルのID
	*/
	Object(D3DXVECTOR3	pos, float angle, int xFileID);
	virtual	~Object();

	/**コントロール関数*/
	virtual void		Control() = 0;

	/**描画関数*/
	virtual void		Draw() = 0;

	/**衝突判定処理*/
	virtual void		InformCollision() = 0;

	/**
	* 消失確認関数
	* @return	消失したかどうか
	* @todo		この関数は衝突判定確認の為、とりあえず実装
	*/
	bool				CheckDisappearance(){return m_HasVanished;}
	
	/**
	* 位置座標取得関数
	* @return 位置座標
	*/
	inline D3DXVECTOR3	GetPos(){ return  m_Pos; }

	/**
	* 衝突判定用半径取得関数
	* @return 半径
	*/
	inline float		GetRadius(){ return  m_Radius; }

protected:
	GameLib&		m_rGameLib;				//!< ライブラリ
	BoundingSphere* m_Sphere;				//!< 衝突判定球
	D3DXVECTOR3		m_Pos;					//!< 位置座標
	D3DXMATRIX		m_MatWorld;				//!< ワールド座標
	float			m_Angle;				//!< 角度
	float			m_Radius;				//!< 半径
	int				m_XFileID;				//!< XファイルID
	bool			m_HasVanished;			//!< 消失フラグ

	/**3D座標変換関数*/
	void Transform3D();

};

#endif // OBJECT_H

