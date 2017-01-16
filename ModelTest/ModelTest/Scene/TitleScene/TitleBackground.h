/**
* @file		TitleBackground.h
* @brief	TitlrBackgroundクラスヘッダ
* @author	haga
*/

#ifndef TITLE_BACKGROUND_H
#define TITLE_BACKGROUND_H

#include <d3dx9.h>

/**
* タイトルの背景を管理するクラス.
*/
class TitleBackground
{

public:
	/**コンストラクタ*/
	TitleBackground();

	/**デストラクタ*/
	~TitleBackground();

	/**フェードイン関数*/
	bool FadeIn();

	/**フェードアウト関数*/
	bool FedeOut();

	/**描画関数*/
	void Draw();

private:
	D3DXVECTOR2			m_Pos;				//!< 位置座標
	BYTE				m_Alpha;			//!< アルファ値
	bool				m_IsFadeInEnd;		//!< フェードインが終了したかどうか
	bool				m_IsFadeOutEnd;		//!< フェードアウトが終了したかどうか

};

#endif	// TITLE_BACKGROUND_H
