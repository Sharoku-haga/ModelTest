/**
* @file		Button.h
* @breif	Buttonクラスヘッダ
* @author	haga
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <d3dx9.h>

/**
* ボタン関連の基底クラス
*/
class Button
{

public:
	/**
	* コンストラクタ.
	* @param	width	横幅
	* @param	height	高さ
	* @param	pos		位置座標
	* @param	texID	テクスチャーID
	* @param	vtxID	バーテックスID
	*/
	Button(float width, float height, D3DXVECTOR2 pos, int texID, int vtxID);
	virtual ~Button();

	/**コントロール関数*/
	virtual void Control() = 0;

	/**描画関数*/
	virtual void Draw() = 0;

protected:
	float			m_Width;		//!< 幅
	float			m_Height;		//!< 高さ
	D3DXVECTOR2		m_Pos;			//!< 位置座標
	int				m_TexID;		//!< テクスチャーID
	int				m_VtxID;		//!< バーテックスID

};

#endif	// BUTTON_H
