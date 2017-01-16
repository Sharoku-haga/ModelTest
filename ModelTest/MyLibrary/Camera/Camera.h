/**
* @file		Camera.h
* @brief	Cameraクラスヘッダ
* @author	haga
*/
#ifndef CAMERA_H
#define CAMERA_H

#define DEFAULT_NEAE_Z	1.0f				//!< 最近点のデフォルト値
#define DEFAULT_FAR_Z	1000.f				//!< 最遠点のデフォルト値

#include <d3dx9.h>

/**
* DirectXのカメラのクラス.
*/
class Camera
{
public:
	/**コンストラクタ*/
	Camera(LPDIRECT3DDEVICE9 pD3Device);
	/**デストラクタ*/
	~Camera();

	/**
	* ウインドウの幅と高さを取得す る関数<br>
	* @param[in] wWidth ウィンドウの幅
	* @param[in] wHeight ウィンドウの高さ
	*/
	void InitWindowSize(float winWidth, float winHeight);

	/**
	* 最近点の値をセットする関数.
	* @param[in] nearZ	設定したい最近点
	*/
	void SetNearZ(float nearZ);

	/**
	* 最遠点の値をセットする関数.
	* @param[in] farZ	設定したい最遠点
	*/
	void SetFarZ(float farZ);

	/**
	* 視点座標変換と射影座標変換を行う関数.
	* @param[in] vEyePt			カメラの位置
	* @param[in] vLookatPt	    注視点
	* @param[in] zoomAngle		視野角
	* @param[in] angle			位置座標角度
	*/
	void LookInCamera(const D3DXVECTOR3* vEyePt, const D3DXVECTOR3* vLookatPt, const float zoomAngle);

private:
	LPDIRECT3DDEVICE9		m_pD3Device;		//!< Direct3Dのデバイス
	float					m_windowWidth;		//!< ウィンドウサイズ幅
	float					m_windowHeight;		//!< ウィンドウサイズ高さ
	float					m_NearZ;			//!< 最近点
	float					m_FarZ;				//!< 最遠点
};

#endif // CAMERA_H
