/**
* @file		BoundingSphere.cpp
* @brief	BoundingSphereクラス実装
* @author	haga
*/

//-------------------------------------------------------------------------------------------------------------//
//Includes
//-------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "BoundingSphere.h"

//-------------------------------------------------------------------------------------------------------------//
//Unnmaed namespace
//-------------------------------------------------------------------------------------------------------------//

namespace
{

const UINT	Slices = 32;			// スライス数.中心を通るように分けた数
const UINT	Stacks = 16;			// スタック数.輪切りの数

}

//-------------------------------------------------------------------------------------------------------------//
//Public finctions
//-------------------------------------------------------------------------------------------------------------//

BoundingSphere::BoundingSphere()
	: m_pMesh(NULL)
	, m_pMaterials(new D3DMATERIAL9)
	, m_CenterPos({0.0f, 0.0f, 0.0f})
{
}

BoundingSphere::~BoundingSphere()
{
	if(m_pMaterials != NULL)
	{
		delete m_pMaterials;
		m_pMaterials = NULL;
	}

	if(m_pMesh != NULL)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
}

void BoundingSphere::CreateSphere(float	radius)
{
	HRESULT hr = NULL;

	hr = D3DXCreateSphere(GameLib::Instance().GetDevice(), radius, Slices, Stacks,&m_pMesh,NULL);

	if(FAILED(hr))
	{
		MessageBox(0, "スフィア作成に失敗しています。", NULL, MB_OK);
	}
	
	// スフィアメッシュのマテリアル.
	// 数値は固定している
	// 設定: 白色 半透明 光沢強
	m_pMaterials->Diffuse.r = 1.0f;
	m_pMaterials->Diffuse.g = 1.0f;
	m_pMaterials->Diffuse.b = 1.0f;
	m_pMaterials->Diffuse.a = 0.3f;
	m_pMaterials->Ambient = m_pMaterials->Diffuse;
	m_pMaterials->Specular.r = 1.0f;
	m_pMaterials->Specular.g = 1.0f;
	m_pMaterials->Specular.b = 1.0f;
	m_pMaterials->Emissive.r = 0.1f;
	m_pMaterials->Emissive.g = 0.1f;
	m_pMaterials->Emissive.b = 0.1f;
	m_pMaterials->Power = 120.f;
	
}

void BoundingSphere::Draw()
{
	GameLib::Instance().GetDevice()->SetMaterial(m_pMaterials);
	m_pMesh->DrawSubset(0);
}
