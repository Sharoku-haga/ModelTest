/**
* @file		CameraController.h
* @brief	CameraControllerクラスヘッダ
* @author	haga
*/

#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <d3dx9.h>

class Camera;

/**
* カメラを操作するクラス.
*/
class CameraController
{

public:

	/**
	* 実体を作成する関数<br>
	* Singletonパターン
	*/
	static CameraController& Instance()
	{
		static CameraController cameraController;
		return cameraController;
	}

	/**コントロール関数*/
	void Control();

	/**注視点を中心にした回転を制御する関数*/
	void Rotate();

	/**ビュー変換関数*/
	void TransformView();

	/**Setter*/
	void SetVLookPt(const D3DXVECTOR3& objPos);
	void SetOldVLookPt(const D3DXVECTOR3& objPos);
	void SetVEyePt(const D3DXVECTOR3& objPos);

	/**カメラ座標にオブジェクトのスピードを加える関数*/
	void AddVEyePt(const D3DXVECTOR3& objSpeed);

	/**初期化関数*/
	void Init();

	~CameraController();

private:
	Camera*			m_pCamera;				//!< Cameraクラスのインスタンスへのポインタ
	D3DXVECTOR3		m_vEyePt;				//!< カメラの位置
	D3DXVECTOR3		m_OldVEyePt;			//!< 前のカメラ位置
	D3DXVECTOR3		m_vLookPt;				//!< カメラの注視点
	float			m_ZoomAngle;			//!< カメラのズーム倍率

	/**Singletonパターンの為private*/
	CameraController();

};

#endif	// CAMERA_CONTROLLER_H
