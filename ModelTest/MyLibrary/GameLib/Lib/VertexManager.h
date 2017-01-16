﻿/**
* @file		VertexManager.h
* @brief	VertexManagerクラスヘッダ
* @author	haga
*/
#ifndef VERTEX_MANAGER_H
#define VERTEX_MANAGER_H

#include <map>
#include "Vertex.h"

/**
* Vertexクラスを管理するクラス
*/
class VertexManager
{
public:
	/**コンストラクタ*/
	VertexManager();
	/**デストラクタ*/
	~VertexManager();

	/**
	* バーテックスクラスを作成し、登録する関数.
	* @param[in] key	mapのキー
	* @param[in] width	横幅(X軸)
	* @param[in] height 高さ(Y軸)
	* @param[in] depth  奥行(Z軸)
	* @param[in] tuMax  tu値の最大値
	* @param[in] tvMax  tv値の最大値
	* @param[in] tuMin  tu値の最小値
	* @param[in] tvMin  tv値の最小値
	*/
	void CreateVertex(int key,float width, float height, float depth = 0.0f,
		float tuMax = 1.0f, float tvMax = 1.0f, float tuMin = 0.0f, float tvMin = 0.0f);

	/**
	* XY軸で描画する関数
	* @param[in] key		mapのキー
	* @param[in] pTexture   テクスチャーを格納先
	* @param[in] x			x座標
	* @param[in] y			y座標
	*/
	void Draw(int key, LPDIRECT3DTEXTURE9 pTexture,float x,float y);

	/**
	* XZ軸で描画する関数
	* @param[in] key		mapのキー
	* @param[in] pTexture   テクスチャーを格納先
	* @param[in] x			x座標
	* @param[in] y			y座標
	* @param[in] z			z座標
	*/
	void Draw(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y, float z);

	/**
	* XY軸でバーテックスの中心座標で描画する関数
	* @param[in] key		mapのキー
	* @param[in] pTexture   テクスチャーを格納先
	* @param[in] x			x座標
	* @param[in] y			y座標
	* @param[in] z			z座標(デフォルト引数は0.0f)
	*/
	void DrawCenterPosXY(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y, float z = 0.0f);

	/**
	* XZ軸でバーテックスの中心座標で描画する関数
	* @param[in] key		mapのキー
	* @param[in] pTexture   テクスチャーを格納先
	* @param[in] x			x座標
	* @param[in] y			y座標
	* @param[in] z			z座標
	*/
	void DrawCenterPosXZ(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y,float z);

	/**
	* XY軸でバーテックスの中心座標で3Dで描画する関数
	* @param[in] key		mapのキー
	* @param[in] pTexture   テクスチャーを格納先
	*/
	void Draw3DCenterPos(int key, LPDIRECT3DTEXTURE9 pTexture);

	/**
	* サイズを変更する関数
	* @param[in] key	mapのキー
	* @param[in] width	横幅(X軸)
	* @param[in] height 高さ(Y軸)
	* @param[in] depth  奥行(Z軸)
	*/
	void SetSize(int key, float width, float height, float depth = 0.0f);

	/**
	* tu値とtv値を変更する関数
	* @param[in] key	mapのキー
	* @param[in] tuMin  tu値の最小値
	* @param[in] tuMax  tu値の最大値
	* @param[in] tvMin  tv値の最小値
	* @param[in] tvax	tv値の最大値
	*/
	void SetTuTv(int key, float tuMin, float tuMax, float tvMin, float tvMax);

	/**
	* 色を変更する関数
	* @param[in] key	mapのキー
	* @param[in] color  色
	*/
	void SetColor(int key, DWORD color);

	/**
	* 拡縮における倍率の設定
	* @param[in] key	mapのキー
	* @param[in] isScailing 拡縮するかどうかのフラグ(基本はfalse)
	* @param[in] magX x座標に処理する倍率
	* @param[in] magY y座標に処理する倍率
	* @param[in] magZ z座標に処理する倍率
	*/
	void SetMagnification(int key, bool isScailing, float magX = 1, float magY = 1, float magZ = 1);

	/**
	* バーテックスを解放する関数
	* @param[in] key	mapのキー
	*/
	void Release(int key);

	/**全てのバーテックスを解放する関数*/
	void ReleaseALL();

private:
		std::map<int, Vertex> m_vertex;				//!< バーテックスクラスを格納する変数 

};

#endif	// VERTEX_MANAGER_H
