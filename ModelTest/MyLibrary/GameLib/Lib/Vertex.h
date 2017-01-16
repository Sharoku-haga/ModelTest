/**
* @file		Vertex.h
* @brief	Vertexクラスヘッダ
* @author	haga
*/
#ifndef VERTEX_H
#define VERTEX_H

#include "GraphicsDevice.h"

/**
* カスタムバーテックス構造体.
*/
struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;	//!< 座標系
	DWORD	color;			//!< 色
	FLOAT	tu, tv;			//!< テクスチャーのtu,tv値
};

struct CUSTOMVERTEX3D
{
	FLOAT	x, y, z;		//!< 座標系
	DWORD	color;			//!< 色
	FLOAT	tu, tv;			//!< テクスチャーのtu,tv値
};

#define USER_VTX_FVF (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)


/**
* バーテックスクラス
*/
class Vertex
{
public:
	
	/**
	* コンストラクタ.
	* 数値を指定するときに使用<br>
	* 奥行も指定する場合に作成.
	* @param[in] width  幅
	* @param[in] height 高さ
	* @param[in] deoth	奥行き
	* @param[in] tuMax	 tu値の最大値
	* @param[in] tvMax	 tv値の最大値
	* @param[in] tuMin	 tu値の最小値
	* @param[in] tvMin	 tv値の最小値
	*/
	Vertex(float width = 0.0f,float height = 0.0f,float depth = 0.0f,float tuMax = 1.0f,float tvMax = 1.0f,float tuMin = 0.0f,float tvMin = 0.0f);

	/**デストラクタ*/
	~Vertex();

	/**
	* 通常描画関数<br>
	* テクスチャーの左上に座標をセットする<br>
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標
	* @param[in] posY     Y座標
	*/
	void Draw(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY);

	/**
	* 通常描画関数<br>
	* テクスチャーの左上に座標をセットする<br>
	* こちらはZ座標も引数として渡す.
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標
	* @param[in] posY     Y座標
	* @param[in] posZ	  Z座標(デフォルト引数は0.0f)
	*/
	void Draw(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ);

	/**
	* 描画関数<br>
	* テクスチャーの中心に座標をセットする<br>
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標
	* @param[in] posY     Y座標
	* @param[in] posZ	  Z座標(デフォルト引数は0.0f)
	*/
	void DrawCenterPosXY(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ = 0.0f);

	/**
	* 描画関数<br>
	* テクスチャーの中心に座標をセットする<br>
	* Z座標も引数として渡す.
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標
	* @param[in] posY     Y座標
	* @param[in] posZ	  Z座標
	*/
	void DrawCenterPosXZ(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ);

	/**
	* 描画関数<br>
	* テクスチャーの中心に座標をセットする<br>
	* Z座標も引数として渡す.
	* @param[in] pTexture テクスチャークラスのポインタ
	*/
	void Draw3DCenterPos(LPDIRECT3DTEXTURE9 pTexture);

	/**
	* テクスチャーサイズをセットする関数.
	* @param[in] texWidth  テクスチャーの幅
	* @param[in] texHeight テクスチャーの高さ
	*/
	void SetTexSize(float texWidth, float texHeight);

	/**
	* tu,tv値を設定する関数.
	* @param[in] tuMin tu値の最小値
	* @param[in] tuMax tu値の最大値
	* @param[in] tvMin tv値の最小値
	* @param[in] tvMax tv値の最大値
	*/
	void SetTuTvVal(float tuMin,float tuMax, float tvMin,float tvMax);

	/**
	* テクスチャー色をセットする関数.
	* @param[in] color  色の設定
	*/
	void SetColor(DWORD color);


	/**
	* 拡縮の設定をする関数
	* @param[in] isScailing 拡縮するかどうかのフラグ(基本はfalse)
	* @param[in] magX x座標に処理する倍率
	* @param[in] magY y座標に処理する倍率
	* @param[in] magZ z座標に処理する倍率
	*/
	void SetMag(bool isScailing, float magX = 1, float magY = 1, float magZ = 1);

	/**
	* 拡縮を行う関数
	* @param[out] vtx 拡縮を行いたいバーテックス
	* @param xzFlag xz平面で行うかどうかのフラグ基本はxy(false)
	*/
	void ScaleGeometry(CUSTOMVERTEX* vtx,bool xzFlag = false);

private:
	IDirect3DDevice9*		m_pD3Device;			//!< デバイス
	float					m_texWidth;		  	    //!< テクスチャーの幅
	float					m_texHeight;			//!< テクスチャーの高さ
	float					m_texDepth;				//!< テクスチャーの奥行き
	float					m_tuMax;				//!< テクスチャーのtu最大値
	float					m_tuMin;				//!< テクスチャーのtu最小値
	float					m_tvMax;				//!< テクスチャーのtv最大値
	float					m_tvMin;				//!< テクスチャーのtv最小値
	DWORD                   m_color[4];				//!< 色の値
	D3DXVECTOR3				m_mag;					//!< 拡縮の倍率
	bool					m_isScaling;			//!< 拡縮するかどうかのフラグ

	/**
	* 行列を用いて平行移動させる関数
	* @param[out] vtx 移動させたいバーテックス
	* @param[in] x	x軸においての移動量
	* @param[in] y  y軸においての移動量
	* @param[in] z  z軸においての移動量
	*/
	void MoveMatrix(CUSTOMVERTEX* vtx, float x, float y, float z);
};

#endif		// VERTEX_H 
