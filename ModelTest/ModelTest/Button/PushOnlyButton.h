/**
* @file		PushOnlyButton.h
* @brief	PushOnlyButtonクラスヘッダ
* @author	haga
*/

#ifndef PUSH_ONLY_BUTTON_H
#define	PUSH_ONLY_BUTTON_H	

#include "Button.h"

/**
* 押すだけのボタンのクラス
*/
class PushOnlyButton :public Button
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
	PushOnlyButton(float width, float height, D3DXVECTOR2 pos, int texID, int vtxID);
	virtual ~PushOnlyButton();

	/**コントロール関数*/
	virtual void Control()override;

	/**描画関数*/
	virtual void Draw()override;

private:
	BYTE		m_Alpha;			//!< アルファ値
	bool		m_IsFadeIn;			//!< FadeInかどうか。trueはFadeIn,falseはFadeOut

	/**フェードイン、フェードアウトを行う関数*/
	void FadeInOut();

};

#endif	// PUSH_ONLY_BUTTON_H
