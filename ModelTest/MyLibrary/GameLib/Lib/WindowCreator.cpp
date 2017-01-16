/**
* @file		WindowCreator.cpp
* @brief	WindowCreatorクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include <windows.h>
#include "WindowCreator.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

WindowCreator::WindowCreator(TCHAR*  title, int width, int height)
	: m_hWnd(NULL)
	, m_wTitle(title)
	, m_wWidth(width)
	, m_wHeight(height)
	, m_IsFullScreen(false)
	, m_hasIcon(false)
{
}

WindowCreator::~WindowCreator()
{
}

// ウィンドウを作成する関数
HRESULT WindowCreator::MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM), bool isFullScreen)
{
	// ウィンドウ情報の設定
	m_wndc.cbSize = sizeof(m_wndc);
	m_wndc.style = CS_HREDRAW | CS_VREDRAW;
	m_wndc.lpfnWndProc = WndProc;
	m_wndc.cbClsExtra = m_wndc.cbWndExtra = 0;
	m_wndc.hInstance = hInstance;
	if(m_hasIcon)
	{
		m_wndc.hIcon = m_hIcon;
	}
	else
	{
		m_wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	}
	m_wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_wndc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_wndc.lpszMenuName = NULL;
	m_wndc.lpszClassName = m_wTitle;
	m_wndc.hIconSm = NULL;

	if(!RegisterClassEx(&m_wndc))
	{
		MessageBox(0, "ウィンドウクラスの設定に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	m_IsFullScreen = isFullScreen;  // ウィンドウタイプがどちらかを保持する

	// ウィンドウを作る	
	if(!m_IsFullScreen)			// 通常ウィンドウ
	{
		m_hWnd = CreateWindow(
			m_wTitle,							// ウィンドウのクラス名
			m_wTitle, 							// ウィンドウのタイトル
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,	// ウィンドウスタイル
			CW_USEDEFAULT,						// ウィンドウの横方向の位置x
			CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
			m_wWidth,							// Width（幅）　
			m_wHeight,							// Height（高さ)
			NULL,
			NULL,
			hInstance,							// アプリケーションインスタンスのハンドル
			NULL
			);

		SetProcessDPIAware();					// ウィンドウサイズを調整する関数

		// クライアント領域を調整する
		RECT client_rect;
		RECT widow_rect;
		GetWindowRect(m_hWnd, &widow_rect);
		GetClientRect(m_hWnd, &client_rect);

		// 正しいウィンドウ間隔を求める(幅)
		widow_rect.right -= widow_rect.left;
		client_rect.right -= client_rect.left;

		// 正しいウィンドウ間隔を求める(高さ)
		widow_rect.bottom -= widow_rect.top;
		client_rect.bottom -= client_rect.top;

		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, ( m_wWidth + ( widow_rect.right - client_rect.right ) ), ( m_wHeight + ( widow_rect.bottom - client_rect.bottom ) ), SWP_NOMOVE);

		GetWindowRect(m_hWnd, &m_wRect);		// 作ったウィンドウサイズを保持しておく
	}
	else				// フルスクリーン
	{
		m_hWnd = CreateWindow(
			m_wTitle,							// ウィンドウのクラス名
			m_wTitle, 							// ウィンドウのタイトル
			WS_POPUP | WS_VISIBLE,				// ウィンドウスタイル
			0,									// ウィンドウの横方向の位置x
			0,									// ウィンドウの縦方向の位置y
			m_wWidth,							// Width（幅）　
			m_wHeight,							// Height（高さ)
			NULL,
			NULL,
			hInstance,							// アプリケーションインスタンスのハンドル
			NULL
			);
	}
	if(!m_hWnd)
	{
		MessageBox(0, "ウィンドウ生成に失敗しました。", NULL, MB_OK);
		return E_FAIL;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	return S_OK;
}

// アイコンを作成する関数
void WindowCreator::CreateIcon(WORD iconID)
{
	HINSTANCE hInstance = GetModuleHandle(NULL);

	m_hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(iconID));

	DWORD error = GetLastError();

	m_hasIcon = true;		// アイコン作成したフラグをたてる
}

// ウィンドウサイズを決定する
HRESULT WindowCreator::ChangeWindowSize()
{
	if(!m_IsFullScreen)
	{
		SetWindowLong(m_hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		m_IsFullScreen = true;
	}
	else
	{
		SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, m_wWidth, m_wHeight, SWP_NOMOVE);

		// クライアント領域を調整する
		RECT client_rect;
		RECT widow_rect;
		GetWindowRect(m_hWnd, &widow_rect);
		GetClientRect(m_hWnd, &client_rect);

		// 正しいウィンドウ間隔を求める(幅)
		widow_rect.right -= widow_rect.left;
		client_rect.right -= client_rect.left;

		// 正しいウィンドウ間隔を求める(高さ)
		widow_rect.bottom -= widow_rect.top;
		client_rect.bottom -= client_rect.top;

		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, ( m_wWidth + ( widow_rect.right - client_rect.right ) ), ( m_wHeight + ( widow_rect.bottom - client_rect.bottom ) ), SWP_NOMOVE);
		GetWindowRect(m_hWnd, &m_wRect);

		m_IsFullScreen = false;
	}
	return S_OK;
}
