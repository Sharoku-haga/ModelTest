/**
* @file		TeamLogo.h
* @brief	TeamLogoクラスヘッダ
* @author	haga
*/

#ifndef TEAM_LOGO_H
#define TEAM_LOGO_H

#include <d3dx9.h>

/**
* チームロゴを管理するクラス.
*/
class TeamLogo
{

public:
	/**コンストラクタ*/
	TeamLogo();

	/**デストラクタ*/
	~TeamLogo();

	/***/
	bool Control();
	void Draw();

private:
	enum STATE
	{
		FADE_IN,		//!< フェードイン
		DISPLAY,		//!< 表示
		FADE_OUT,		//!< フェードアウト
		HIDE,			//!< 非表示
	};
	D3DXVECTOR2		m_Pos;					//!< 位置座標
	BYTE			m_Alpha;				//!< アルファ値
	TeamLogo::STATE m_State;				//!< ロゴの状態
	bool			m_IsFadeEnd;			//!< フェードインアウトが終わったかどうか	
	int				m_DispTimeCount;		//!< 表示時間をカウントする変数

};

#endif	// TEAM_LOGO_H
