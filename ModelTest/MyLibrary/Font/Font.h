﻿/**
* @file		Font.h
* @brief	Fontクラスヘッダ
* @author	haga
*/
#ifndef FONT_H
#define FONT_H

#include<d3dx9.h>

/**
* フォントを扱うクラス.
*/
class Font
{
public:
	/**
	* コンストラクタ<br>
	* @param[in] pD3Device デバイス
	*/
	Font(IDirect3DDevice9*	pD3Device);

	/**
	* コンストラクタ<br>
	* 文字の大きさを変える場合に使う
	* @param[in] height		文字の高さ
	* @param[in] width		文字の幅
	*/
	Font(IDirect3DDevice9*	pD3Device,INT height, INT width);

	/**デストラクタ*/
	~Font();

	/**
	* テキストを描画する関数.
	* @param[in] pString	表示したい文字列
	* @param[in] pos		テキストを表示したい座標
	*/
	void Draw(LPCTSTR pString,D3DXVECTOR2 pos);

	/**
	* テキストを描画する関数<br>
	* こちらは文字の色を変更できる
	* @param[in] pString	表示したい文字列
	* @param[in] pos		テキストを表示したい座標
	* @param[in] format	テキストタイプ DT_LEFT(左寄せ) or DT_RIGHT(右寄せ) or DT_BOTTOM(下寄せ) or DT_TOP(上寄せ)
	* @param[in] color		文字の色
	*/
	void Draw(LPCTSTR pString, D3DXVECTOR2 pos, DWORD format, D3DCOLOR color);

	/**
	* 文字のフォントなどを再設定する関数
	* @param[in] pFacename	文字フォント
	* @param[in] weight		文字の太さ 基本はFW_REGULAR(通常),FW_BOLD(太字)のどちらかを渡す
	* @param[in] italic		斜体にするかどうか
	*/
	void ReCreateFont(LPCTSTR pFacename, UINT weight, BOOL italic);

	/**
	* 1文字の高さを取得する関数.
	* @return m_height	文字の高さ
	*/
	INT	 GetFontHeight();

private:
	IDirect3DDevice9*	m_pD3Device;		//!< Direct3Dのデバイス
	LPD3DXFONT			m_pFont;			//!< ID3DXFontインターフェイスへのポインタ
	INT					m_height;			//!< 文字の高さ
	UINT				m_width;			//!< 文字の幅


};

#endif		// FONT_H
