/**
* @file			MyLibrary.h
* @brief		MyLibraryのヘッダーファイルをまとめたヘッダ<br>
* @author		haga
* @attention	あくまでこのヘッダーは確認用なのでincludeはしないこと
*/

#define MY_LIBRARY_H

#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

//------------------------------------------------------------------------------
//					MyLibrary内の主なヘッダーファイル
//------------------------------------------------------------------------------

#include "GameLib/GameLib.h"			//!< Facadeパターンのライブラリ
#include "Font/Font.h"					//!< フォントクラス
#include "Camera/Camera.h"				//!< カメラクラス
#include "Light/Light.h"				//!< ライトクラス

/*
設定するLib
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib,"dxguid.lib")
#pragma comment (lib,"shlwapi.lib")
#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"Dsound.lib")
#pragma comment (lib,"MyLibrary.lib")
*/

//----------------------------------------------------------------------------------------
//				以下はGameLibのLibファルダ内のヘッダーファイル
//----------------------------------------------------------------------------------------
#include "GameLib/Lib/WindowCreator.h"				//!< Window関連クラス
#include "GameLib/Lib/GraphicsDevice.h"				//!< GraphicsDeviceのクラス
#include "GameLib/Lib/InputDevice.h"				//!< DirectInputデバイス関連クラス
#include "GameLib/Lib/InputKey.h"					//!< キーボード操作関連クラス
#include "GameLib/Lib/InputMouse.h"					//!< マウス操作関連クラス
#include "GameLib/Lib/TextureManager.h"				//!< テクスチャー管理クラス
#include "GameLib/Lib/XFileManager.h"				//!< Xファイル管理クラス
#include "GameLib/Lib/XFile.h"						//!< Xファイルクラス
#include "GameLib/Lib/SoundFileManager.h"			//!< サウンド管理クラス
#include "GameLib/Lib/VertexManager.h"				//!< 頂点管理クラス
#include "GameLib/Lib/Vertex.h"						//!< 頂点クラス
#include "GameLib/Lib/AnimationInfo.h"				//!< アニメーション情報クラス
#include "GameLib/Lib/AnimationInfoManager.h"		//!< アニメーション情報管理クラス
#include "GameLib/Lib/DebugFont.h"					//!< デバックフォントクラス
#include "GameLib/Lib/DebugTimer.h"					//!< デバックタイマークラス

#endif // MY_LIBRARY_H
