/**
* @file		Effect.cpp
* @brief	Effectクラス実装
* @author	haga
*/

//-------------------------------------------------------------------------------------------------------------//
//Includes
//-------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "../CameraController/CameraController.h"
#include "Effect.h"

//-------------------------------------------------------------------------------------------------------------//
//Public functions
//-------------------------------------------------------------------------------------------------------------//

Effect::Effect(D3DXVECTOR3 pos, int texID, int vtxID)
	: m_Pos(pos)
	, m_TexID(texID)
	, m_VtxID(vtxID)
	, m_IsEnd(false)
{
}

Effect::~Effect()
{
}

//-------------------------------------------------------------------------------------------------------------//
//Protected functions
//-------------------------------------------------------------------------------------------------------------//

void Effect::Transform3D()
{
	D3DXMATRIX matPosition;							// 位置座標行列
	D3DXMatrixIdentity(&m_MatWorld);
	D3DXMatrixTranslation(&matPosition,m_Pos.x,m_Pos.y,m_Pos.z);
	ChangeBillboarding();							// ビルボード変換
	D3DXMatrixMultiply(&m_MatWorld,&m_MatWorld,&matPosition);
	GameLib::Instance().GetDevice()->SetTransform(D3DTS_WORLD, &m_MatWorld);
	CameraController::Instance().TransformView();
}

// ビルボードにするための関数
void Effect::ChangeBillboarding()
{
	D3DXMATRIX matCuurentView;		// 現在のビュー行列を格納する変数
	GameLib::Instance().GetDevice()->GetTransform(D3DTS_VIEW,&matCuurentView);
	D3DXMatrixInverse(&matCuurentView, NULL, &matCuurentView);			// 逆行列作成
	matCuurentView._41 = 0.0f;
	matCuurentView._42 = 0.0f;
	matCuurentView._43 = 0.0f;
	D3DXMatrixMultiply(&m_MatWorld,&m_MatWorld,&matCuurentView);		
}
