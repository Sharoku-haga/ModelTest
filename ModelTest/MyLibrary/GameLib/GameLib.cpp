/**
* @file		GameLib.cpp
* @brief	GameLibクラス実装
* @author	haga
*/

//----------------------------------------------------------------------------------------------------//
//Includes
//----------------------------------------------------------------------------------------------------//

#include "Lib/WindowCreator.h"	
#include "Lib/GraphicsDevice.h"
#include "Lib/InputDevice.h"
#include "Lib/InputMouse.h"
#include "Lib/TextureManager.h"
#include "Lib/XFileManager.h"
#include "Lib/SoundFileManager.h"
#include "Lib/VertexManager.h"
#include "Lib/AnimationInfoManager.h"
#include "Lib/DebugFont.h"
#include "Lib/DebugTimer.h"
#include "GameLib.h"

//-----------------------------------------------------------------------------------------------------//
//Private functions
//-----------------------------------------------------------------------------------------------------//

GameLib::GameLib()
	: m_pWindowCreator(NULL)
	, m_pGraphicsDevice(NULL)
	, m_pInputDevice(NULL)
	, m_pSoundFileManager(NULL)
	, m_pInputMouse(NULL)
	, m_pInputKey(NULL)
	, m_pTextureManager(NULL)
	, m_pXFileManager(NULL)
	, m_pVertexManager(NULL)
	, m_pAnimationInfoManager(NULL)
	, m_wWidth(0)
	, m_wHeight(0)
{
}


//-----------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------//

GameLib::~GameLib()
{
	ReleaseGameLib();
}

// 初期化関数
void GameLib::InitGameLib(TCHAR*  title, int width, int height, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM),
	bool isFullScreen, bool hasIcon, WORD iconID)
{
	m_wWidth = width;
	m_wHeight = height;
	HINSTANCE hInstance = GetModuleHandle(NULL);

	m_pWindowCreator = new WindowCreator(title, width, height);

	if(hasIcon)
	{
		m_pWindowCreator->CreateIcon(iconID);
	}

	m_pGraphicsDevice = &GraphicsDevice::GetInstance();

	m_pWindowCreator->MakeWindow(hInstance, WndProc, isFullScreen);
	m_pGraphicsDevice->InitDevice(m_pWindowCreator->GetHwnd(), isFullScreen, m_wWidth, m_wHeight);

	m_pGraphicsDevice->SetRenderState3D();

	m_pInputDevice = &InputDevice::GetInstance();
	m_pInputDevice->InitDinput();
	m_pInputDevice->InitDinputKey(m_pWindowCreator->GetHwnd());
	m_pInputDevice->InitDinputMouse(m_pWindowCreator->GetHwnd());
	m_pInputKey = new InputKey();
	m_pInputMouse = new InputMouse();

	m_pSoundFileManager = &SoundFileManager::GetInstance();
	m_pSoundFileManager->InitSound(m_pWindowCreator->GetHwnd());

	m_pTextureManager = new TextureManager();
	m_pXFileManager = new XFileManager();
	m_pVertexManager = new VertexManager();
	m_pAnimationInfoManager = new AnimationInfoManager();
	m_pDebugTimer = new DebugTimer();
}

// メモリ開放関数
void GameLib::ReleaseGameLib()
{
		delete m_pDebugTimer;
		m_pDebugTimer = NULL;

		delete m_pAnimationInfoManager;
		m_pAnimationInfoManager = NULL;

		delete m_pVertexManager;
		m_pVertexManager = NULL;

		delete m_pXFileManager;
		m_pXFileManager = NULL;

		delete m_pTextureManager;
		m_pTextureManager = NULL;

		delete m_pInputMouse;
		m_pInputMouse = NULL;

		delete m_pInputKey;
		m_pInputKey = NULL;

		delete m_pWindowCreator;
		m_pWindowCreator = NULL;
}

// ウィンドウタイプを変える関数
void GameLib::ChangeWindowMode()
{
	m_pGraphicsDevice->ChangeDisplayMode();
	m_pWindowCreator->ChangeWindowSize();
}

// ウィンドウの横幅を取得する関数
int GameLib::GetWindowWidth()
{
	return m_wWidth;
}

// ウィンドウの縦幅を取得する関数
int GameLib::GetWindowHeight()
{
	return m_wHeight;
}

// デバイスを取得する関数
IDirect3DDevice9* GameLib::GetDevice()
{
	return ( m_pGraphicsDevice->GetDevice() );
}

// 描画開始処理関数
void GameLib::StartRender(DWORD FVF)
{
	m_pGraphicsDevice->StartRender(FVF);
}

// 描画終了処理関数
void GameLib::EndRender()
{
	m_pGraphicsDevice->EndRender();
}

// 頂点フォーマットを設定する関数
void GameLib::SetFVF(DWORD FVF)
{
	m_pGraphicsDevice->SetFVF(FVF);
}

// テクスチャーを読み込む関数
void GameLib::LoadTex(int key, TCHAR* filePath)
{
	m_pTextureManager->Load(key, filePath);
}

// テクスチャーを詳細設定して読み込む関数
void GameLib::LoadTexEx(int key, TCHAR* filePath, int a, int r, int g, int b, bool size)
{
	m_pTextureManager->LoadEx(key, filePath, a, r, g, b, size);
}

// バーテックスを作成する関数
void GameLib::CreateVtx(int key, float width, float height, float depth)
{
	m_pVertexManager->CreateVertex(key, width, height, depth);
}

// バーテックスの変更を行う関数
void GameLib::SetVtxUV(int key, float tuMin, float tuMax, float tvMin, float tvMax)
{
	m_pVertexManager->SetTuTv(key, tuMin, tuMax, tvMin, tvMax);
	
}

// 色変更
void GameLib::SetVtxColor(int key, DWORD color)
{
	m_pVertexManager->SetColor(key, color);
}

// 拡縮における倍率の設定
void GameLib::SetMag(int key, bool isScailing, D3DXVECTOR3 mag)
{
	m_pVertexManager->SetMagnification(key, isScailing, mag.x, mag.y, mag.z);
}

// アニメーション情報を登録する関数
void GameLib::RegisterAnimationInfo(int key, int aniPat, int interval,
	float intervalTu, float intervalTv, bool isReverse)
{
	m_pAnimationInfoManager->RegisterAnimationInfo(key, aniPat, interval, intervalTu, intervalTv, isReverse);
}

// アニメの情報をセットする関数
void GameLib::SetAnimeInfo(int key, int animeNum, float minTu, float maxTu, float minTv, float maxTv)
{
	m_pAnimationInfoManager->SetAnimeInfo(key, animeNum, minTu, maxTu, minTv, maxTv);
}

// テクスチャー(XY座標)を描画する関数
void GameLib::DrawXY(int texKey, int vtxKey, float posX, float posY)
{
	m_pVertexManager->Draw(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY);
}

// テクスチャー(XY座標)の中心に座標を合わせて描画する関数
void GameLib::DrawXYCenterPos(int texKey, int vtxKey, float posX, float posY, float posZ)
{
	m_pVertexManager->DrawCenterPosXY(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

// テクスチャー(XY座標)でアニメーションを行いながら描画する関数
void GameLib::DrawAnimeXY(int texKey, int vtxKey, int animeKey, float posX, float posY)
{
	m_pAnimationInfoManager->ControlAnime(animeKey);

	m_pVertexManager->SetTuTv(vtxKey
		, m_pAnimationInfoManager->GetMinTu(animeKey)
		, m_pAnimationInfoManager->GetMaxTu(animeKey)
		, m_pAnimationInfoManager->GetMinTv(animeKey)
		, m_pAnimationInfoManager->GetMaxTv(animeKey)
		);

	m_pVertexManager->Draw(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY);
}

// テクスチャー(XY座標)の中心に座標を合わせてアニメーションを行いながら描画する関数
void GameLib::DrawAnimeXYCenterPos(int texKey, int vtxKey, int animeKey, float posX, float posY, float posZ)
{
	m_pAnimationInfoManager->ControlAnime(animeKey);

	m_pVertexManager->SetTuTv(vtxKey
		, m_pAnimationInfoManager->GetMinTu(animeKey)
		, m_pAnimationInfoManager->GetMaxTu(animeKey)
		, m_pAnimationInfoManager->GetMinTv(animeKey)
		, m_pAnimationInfoManager->GetMaxTv(animeKey)
		);

	m_pVertexManager->DrawCenterPosXY(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

// テクスチャー(XZ座標)を描画する関数
void GameLib::DrawXZ(int texKey, int vtxKey, float posX, float posY, float posZ)
{
	m_pVertexManager->Draw(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

// テクスチャー(XZ座標)の中心に座標を合わせて描画する関数
void GameLib::DrawXZCenterPos(int texKey, int vtxKey, float posX, float posY, float posZ)
{
	m_pVertexManager->DrawCenterPosXZ(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

// テクスチャー(XZ座標)でアニメーションを行いながら描画する関数
void GameLib::DrawAnimeXZ(int texKey, int vtxKey, int animeKey, float posX, float posY, float posZ)
{
	m_pAnimationInfoManager->ControlAnime(animeKey);

	m_pVertexManager->SetTuTv(vtxKey
		, m_pAnimationInfoManager->GetMinTu(animeKey)
		, m_pAnimationInfoManager->GetMaxTu(animeKey)
		, m_pAnimationInfoManager->GetMinTv(animeKey)
		, m_pAnimationInfoManager->GetMaxTv(animeKey)
		);

	m_pVertexManager->Draw(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

// テクスチャー(XZ座標)の中心に座標を合わせてアニメーションを行いながら描画する関数
void GameLib::DrawAnimeXZCenterPos(int texKey, int vtxKey, int animeKey, float posX, float posY, float posZ)
{
	m_pAnimationInfoManager->ControlAnime(animeKey);

	m_pVertexManager->SetTuTv(vtxKey
		, m_pAnimationInfoManager->GetMinTu(animeKey)
		, m_pAnimationInfoManager->GetMaxTu(animeKey)
		, m_pAnimationInfoManager->GetMinTv(animeKey)
		, m_pAnimationInfoManager->GetMaxTv(animeKey)
		);

	m_pVertexManager->DrawCenterPosXZ(vtxKey, m_pTextureManager->GetTex(texKey), posX, posY, posZ);
}

void GameLib::Draw3DCenterPos(int texKey, int vtxKey)
{
	m_pVertexManager->Draw3DCenterPos(vtxKey, m_pTextureManager->GetTex(texKey));
}

// テクスチャーのポインタを取得する関数
LPDIRECT3DTEXTURE9 GameLib::GetTexture(int texKey)
{
	return m_pTextureManager->GetTex(texKey);
}

// テクスチャーを解放する関数
void GameLib::ReleaseTex(bool isAll, int key)
{
	if(isAll)			// すべて破棄するなら
	{
		m_pTextureManager->ReleaseALL();
		m_pVertexManager->ReleaseALL();
	}
	else
	{
		if(key != INT_MAX)
		{
			m_pTextureManager->Release(key);
			m_pVertexManager->Release(key);
		}
	}
}

// バーテックスを解放する関数
void GameLib::ReleaseVtx(bool isAll, int key)
{
	if(isAll)			// すべて破棄するなら
	{
		m_pVertexManager->ReleaseALL();
	}
	else
	{
		if(key != INT_MAX)
		{
			m_pVertexManager->Release(key);
		}
	}
}

// アニメーション情報を解放する関数
void GameLib::ReleaseAnimeInfo(bool isAll, int key)
{
	if(isAll)			// すべて破棄するなら
	{
		m_pAnimationInfoManager->ReleaseALL();
	}
	else
	{
		if(key != INT_MAX)
		{
			m_pAnimationInfoManager->Release(key);
		}
	}
}

// Xファイルを読み込む関数
void GameLib::LoadXFile(int key, LPCTSTR pFilePath)
{
	m_pXFileManager->Load(key, pFilePath);
}

// Xファイルを描画する関数
void GameLib::DrawXFile(int key)
{
	m_pXFileManager->Draw(key);
}

// Xファイルを解放する関数
void GameLib::ReleaseXFile(bool isAll, int key)
{
	if(isAll)			// すべて破棄するなら
	{
		m_pXFileManager->ReleaseALL();
	}
	else
	{
		if(key != INT_MAX)
		{
			m_pXFileManager->Release(key);
		}
	}
}

// ダイレクトインプットをアップデートする関数
void GameLib::UpdateDI()
{
	m_pInputKey->UpdateKey();
	m_pInputMouse->UpdateMouse();
}

// キーの状態を確認する関数
BUTTON_STATE GameLib::CheckKey(int DIK, KEYKIND keyName)
{
	BUTTON_STATE state;

	switch(m_pInputKey->CheckKey(DIK, keyName))
	{
	case BTN_ON:
		state = ON;
		break;

	case BTN_OFF:
		state = OFF;
		break;

	case BTN_PUSH:
		state = PUSH;
		break;

	case BTN_RELEASE:
		state = RELEASE;
		break;
	}
	return state;
}

// マウスの左ボタンの状態を取得する関数
BUTTON_STATE GameLib::ChecKMouseL()
{
	BUTTON_STATE state;

	switch(m_pInputMouse->ChecKMouse(MouseLeft))
	{
	case BTN_ON:
		state = ON;
		break;

	case BTN_OFF:
		state = OFF;
		break;

	case BTN_PUSH:
		state = PUSH;
		break;

	case BTN_RELEASE:
		state = RELEASE;
		break;
	}
	return state;
}

// マウスの右ボタンの状態を取得する関数
BUTTON_STATE GameLib::ChecKMouseR()
{
	BUTTON_STATE state;

	switch(m_pInputMouse->ChecKMouse(MouseRight))
	{
	case BTN_ON:
		state = ON;
		break;

	case BTN_OFF:
		state = OFF;
		break;

	case BTN_PUSH:
		state = PUSH;
		break;

	case BTN_RELEASE:
		state = RELEASE;
		break;
	}
	return state;
}

// マウスのホイールの状態を取得する関数
WHEEL_STATE GameLib::GetWheelState()
{
	WHEEL_STATE state;

	switch(m_pInputMouse->GetWheelState())
	{
	case WHEEL_NONE:
		state = ROLL_NONE;
		break;

	case WHEEL_UP:
		state = ROLL_UP;
		break;

	case WHEEL_DOWN:
		state = ROLL_DOWN;
		break;
	}
	return state;
}

// マウスの座標を取得する関数
void GameLib::GetMousePos(float* mousePosX, float* mousePosY)
{
	*mousePosX = static_cast<float>( m_pInputMouse->GetPosX() );
	*mousePosY = static_cast<float>( m_pInputMouse->GetPosY() );
}

// マウスの座標をセットする関数
void GameLib::SetMouseCursorPos(float posX, float posY)
{
	m_pInputMouse->SetMouseCursorPos(posX, posY);
}

// マウスカーソルを表示するかどうかを設定する関数
void GameLib::ShowMouseCursor(bool isVisible)
{
	m_pInputMouse->ShowMouseCursor(isVisible);
}

// 音声を読み込む関数
void GameLib::LoadSound(int key, TCHAR* filePath)
{
	m_pSoundFileManager->LoadSound(key, filePath);
}

// 音楽を鳴らす関数
void GameLib::PlayDSound(int key, SOUND_OPERATION operation)
{
	switch(operation)
	{
	case SOUND_PLAY:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::Play);
		break;

	case SOUND_STOP:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::Stop);
		break;

	case SOUND_LOOP:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::PlayLoop);
		break;

	case SOUND_RESET:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::Reset);
		break;

	case SOUND_RESET_PLAY:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::Reset_Play);
		break;

	case SOUND_STOP_RESET:
		m_pSoundFileManager->SoundPlayer(key, SOUND_MODE::Stop_Reset);
		break;
	}
}

// サウンドを解放する関数
void GameLib::ReleaseSound(bool isAll, int key)
{
	if(isAll)			// すべて破棄するなら
	{
		m_pSoundFileManager->ReleaseALL();
	}
	else
	{
		if(key != INT_MAX)
		{
			m_pSoundFileManager->Release(key);
		}
	}
}

// デバック用の文字を表示させる関数
void GameLib::DrawDebugFont(std::string text, float posX, float posY)
{
	DebugFont font;
	font.Draw(text.c_str(), D3DXVECTOR2(posX, posY));
}

// デバック用の時間計測を開始する関数
void GameLib::StartTimer(std::string  timeName)
{
	m_pDebugTimer->SetDebugTimer(timeName);
	m_pDebugTimer->StartTimer(timeName);
}

// デバック用の時間計測を終了する関数
void GameLib::EndTimer(std::string  timeName)
{
	m_pDebugTimer->EndTimer(timeName);
}

// デバック用の計測結果を表示する関数
void GameLib::DrawResult(std::string  timeName, float posX, float posY)
{
	m_pDebugTimer->DrawResult(timeName, D3DXVECTOR2(posX, posY));
}

// デバック用の時間計測した結果を取得する関数
DWORD GameLib::GetResultTime(std::string  timeName)
{
	return ( m_pDebugTimer->GetResult(timeName) );
}

// デバック用の時間計測した結果全てとその合計時間を表示する関数
void GameLib::DrawAllResult(float posX, float posY)
{
	m_pDebugTimer->DrawAllResult(D3DXVECTOR2(posX, posY));
}
