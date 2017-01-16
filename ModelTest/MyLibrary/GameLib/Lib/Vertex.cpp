/**
* @file		Vertex.h
* @brief	Vertexクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "Vertex.h"

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

// コンストラクタ
Vertex::Vertex(float width, float height, float depth, float tuMax, float tvMax, float tuMin, float tvMin)
	: m_pD3Device(GraphicsDevice::GetInstance().GetDevice())
	, m_texWidth(width)
	, m_texHeight(height)
	, m_texDepth(depth)
	, m_tuMax(tuMax)
	, m_tvMax(tvMax)
	, m_tuMin(tuMin)
	, m_tvMin(tuMin)
	, m_mag(0, 0, 0)
	, m_isScaling(false)
{
	for (int i = 0; i < 4; i++)
	{
		m_color[i] = 0xFFFFFFFF;
	}
}

// デストラクタ
Vertex::~Vertex()
{
}

// 描画(XY座標で考える場合)
void Vertex::Draw(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY)
{
	float texWidth = m_texWidth;
	float texHeight = m_texHeight;
	float texDepth = m_texDepth;

	CUSTOMVERTEX vtex[] = {
		{	  0.0f,		 0.0f, texDepth, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{ texWidth,	     0.0f, texDepth, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{ texWidth, texHeight, texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{	  0.0f, texHeight, texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	if (m_isScaling)
	{
		ScaleGeometry(vtex);
	}
	

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
	}

	m_pD3Device->SetTexture(0, pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtex, sizeof(CUSTOMVERTEX));
}

// 描画 XZ座標で考える場合
void Vertex::Draw(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ)
{
	float texWidth = m_texWidth;
	float texHeight = m_texHeight;
	float texDepth = m_texDepth;

	CUSTOMVERTEX vtex[] = {
		{	  0.0f, texHeight,   texDepth, 1.0f, m_color[0], m_tuMin, m_tvMax },
		{ texWidth, texHeight,   texDepth, 1.0f, m_color[1], m_tuMax, m_tvMax },
		{ texWidth, texHeight,		 0.0f, 1.0f, m_color[2], m_tuMax, m_tvMin },
		{	  0.0f, texHeight,		 0.0f, 1.0f, m_color[3], m_tuMin, m_tvMin },
	};

	if (m_isScaling)
	{
		ScaleGeometry(vtex, true);
	}

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
		vtex[i].z += posZ;
	}

	m_pD3Device->SetTexture(0, pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtex, sizeof(CUSTOMVERTEX));
}

// 描画(テクスチャーの中心に座標を合わせる)
void Vertex::DrawCenterPosXY(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ)
{
	float texWidth = m_texWidth;
	float texHeight = m_texHeight;
	float texDepth = m_texDepth;

	CUSTOMVERTEX vtex[] = {
		{ -texWidth / 2, -texHeight / 2, texDepth, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{  texWidth / 2, -texHeight / 2, texDepth, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{  texWidth / 2,  texHeight / 2, texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{ -texWidth / 2,  texHeight / 2, texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	if (m_isScaling)
	{
		ScaleGeometry(vtex);
	}

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
		vtex[i].z += posZ;
	}
	m_pD3Device->SetTexture(0, pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtex, sizeof(CUSTOMVERTEX));
}


// 描画(テクスチャーの中心に座標を合わせる)引数にZ座標追加
void Vertex::DrawCenterPosXZ(LPDIRECT3DTEXTURE9 pTexture, float posX, float posY, float posZ)
{
	float texWidth = m_texWidth;
	float texHeight = m_texHeight;
	float texDepth = m_texDepth;

	CUSTOMVERTEX vtex[] = {
		{ -texWidth / 2, texHeight,  texDepth / 2, 1.0f, m_color[0], m_tuMin, m_tvMax },
		{  texWidth / 2, texHeight,  texDepth / 2, 1.0f, m_color[1], m_tuMax, m_tvMax },
		{  texWidth / 2, texHeight, -texDepth / 2, 1.0f, m_color[2], m_tuMax, m_tvMin },
		{ -texWidth / 2, texHeight, -texDepth / 2, 1.0f, m_color[3], m_tuMin, m_tvMin },
	};

	if (m_isScaling)
	{
		ScaleGeometry(vtex, true);
	}

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
		vtex[i].z += posZ;
	}
	m_pD3Device->SetTexture(0, pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtex, sizeof(CUSTOMVERTEX));
}

void Vertex::Draw3DCenterPos(LPDIRECT3DTEXTURE9 pTexture)
{
	float texWidth = m_texWidth;
	float texHeight = m_texHeight;
	float texDepth = m_texDepth;

	CUSTOMVERTEX3D vtex[] = {
		{ -texWidth / 2.0f,  texHeight / 2.0f, texDepth, m_color[0], m_tuMin, m_tvMin },
		{  texWidth / 2.0f,  texHeight / 2.0f, texDepth, m_color[1], m_tuMax, m_tvMin },
		{  texWidth / 2.0f, -texHeight / 2.0f, texDepth, m_color[2], m_tuMax, m_tvMax },
		{ -texWidth / 2.0f, -texHeight / 2.0f, texDepth, m_color[3], m_tuMin, m_tvMax },
	};

	m_pD3Device->SetFVF(USER_VTX_FVF);
	m_pD3Device->SetTexture(0, pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vtex, sizeof(CUSTOMVERTEX3D));
}

// テクスチャーサイズをセットする関数
void Vertex::SetTexSize(float texWidth, float texHeight)
{
	m_texWidth = texWidth;
	m_texHeight = texHeight;
}

// tu,tv値を設定する関数
void Vertex::SetTuTvVal(float tuMin, float tuMax, float tvMin, float tvMax)
{
	m_tuMin = tuMin;
	m_tvMin = tvMin;
	m_tuMax = tuMax;
	m_tvMax = tvMax;
}

// 色を設定する関数
void Vertex::SetColor(DWORD color)
{
	for (int i = 0; i < 4; i++)
	{
		m_color[i] = color;
	}
}

// 拡縮の設定をする関数
void Vertex::SetMag(bool isScailing, float magX, float magY, float magZ)
{
	m_isScaling = isScailing;
	m_mag.x = magX;
	m_mag.y = magY;
	m_mag.z = magZ;
}

// 拡縮を行う関数
void Vertex::ScaleGeometry(CUSTOMVERTEX* vtx, bool xzFlag)
{
	D3DXMATRIX PosMatrix;		// 頂点行列
	D3DXMATRIX MultipleMatrix;	// 拡大・縮小行列

	float cx = 0.0f;		// 中心座標のx座標を格納する変数
	float cy = 0.0f;		// 中心座標のy座標を格納する変数
	float cz = 0.0f;		// 中心座標のy座標を格納する変数

	if (!xzFlag)
	{
		cx = (vtx[2].x - vtx[0].x) / 2.0f;
		cy = (vtx[2].y - vtx[0].y) / 2.0f;
	}
	else
	{
		cx = (vtx[2].x - vtx[0].x) / 2.0f;
		cz = (vtx[0].z - vtx[2].z) / 2.0f;
	}

	//原点へ移動させる
	MoveMatrix(vtx, -cx, -cy, -cz);

	// 行列の初期化（単位行列生成）
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MultipleMatrix);

	// x 軸、y 軸、z 軸に沿ってスケーリングする行列を作成する。
	D3DXMatrixScaling(&MultipleMatrix, m_mag.x, m_mag.y, m_mag.z);

	// 拡大・縮小処理
	for (int i = 0; i<4; i++)
	{
		// 現在の頂点座標を格納
		D3DXMatrixTranslation(&PosMatrix, vtx[i].x, vtx[i].y, vtx[i].z);
		// 拡大、または縮小
		PosMatrix *= MultipleMatrix;
		// 結果を戻す
		vtx[i].x = PosMatrix._41;
		vtx[i].y = PosMatrix._42;
		vtx[i].z = PosMatrix._43;
	}

	//元の位置に移動させる
	MoveMatrix(vtx, cx, cy, cz);
}

//-----------------------------------------------------------------------------------------------------------//
//Private functions
//-----------------------------------------------------------------------------------------------------------//

// 行列を用いて平行移動する関数
void Vertex::MoveMatrix(CUSTOMVERTEX* vtx, float x, float y, float z)
{
	D3DXMATRIX PosMatrix;
	D3DXMATRIX MoveMatrix;

	// 行列の初期化
	D3DXMatrixIdentity(&PosMatrix);
	D3DXMatrixIdentity(&MoveMatrix);

	// 移動量設定
	D3DXMatrixTranslation(&MoveMatrix, x, y, z);

	// 
	for (int i = 0; i < 4; i++)
	{
		// 現在の頂点座標を格納
		D3DXMatrixTranslation(&PosMatrix, vtx[i].x, vtx[i].y, vtx[i].z);
		// 移動
		PosMatrix *= MoveMatrix;
		// 結果を返す
		vtx[i].x = PosMatrix._41;
		vtx[i].y = PosMatrix._42;
		vtx[i].z = PosMatrix._43;
	}

}
