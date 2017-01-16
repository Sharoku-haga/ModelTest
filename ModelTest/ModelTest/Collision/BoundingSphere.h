/**
* @file		BoundingSphere.h
* @brief	BoundingSphereクラスヘッダ
* @author	haga
*/

#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include <d3dx9.h>

/**
* 衝突判定球を描画するクラス
*/
class BoundingSphere
{

public:
	BoundingSphere();
	~BoundingSphere();

	/**
	* 判定球作成関数.
	* @param	radius
	*/
	void CreateSphere(float	radius);

	/**描画関数*/
	void Draw();

private:
	LPD3DXMESH			m_pMesh;			//!< メッシュ
	D3DMATERIAL9*		m_pMaterials;		//!< マテリアル
	D3DXVECTOR3			m_CenterPos;		//!< 中心座標

};

#endif	// BOUNDING_SPHERE_H
