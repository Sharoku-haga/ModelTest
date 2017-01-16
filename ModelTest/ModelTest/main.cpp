/**
* @file		main.cpp
* @brief	���f���e�X�g�v���O����
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include <windows.h>
#include <crtdbg.h>
#include "GameLib/GameLib.h"
#include "Scene/SceneManager.h"

//------------------------------------------------------------------------------------------------------------//
//Defines
//------------------------------------------------------------------------------------------------------------//

#define WINDOW_MODE							// �E�B���h�E���[�h(�ʏ�)
#define GAME_TITLE TEXT("���f���e�X�g")		// �v���O�����^�C�g��
#define CLIENT_W 1600						// �N���C�A���g�̈�̕�
#define CLIENT_H 900						// �N���C�A���g�̈�̍���
#define GAME_FPS (1000 / 60)				// FPS

//------------------------------------------------------------------------------------------------------------//
//Function prototype
//------------------------------------------------------------------------------------------------------------//

// �E�C���h�E�v���V�[�W��
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//------------------------------------------------------------------------------------------------------------//
//EntryPoint
//------------------------------------------------------------------------------------------------------------//

// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// ���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	//------------------------------------------------------------//
	//GameInit
	//------------------------------------------------------------//

#ifdef WINDOW_MODE
	GameLib::Instance().InitGameLib(GAME_TITLE, CLIENT_W, CLIENT_H, WindowProc, false, false);
#else
	GameLib::Instance().InitGameLib(GAME_TITLE, CLIENT_W, CLIENT_H, WindowProc, true, false);

#endif

	//------------------------------------------------------------//
	//GameLoop
	//------------------------------------------------------------//

	SceneManager* pSceneManager = new SceneManager();

	DWORD currentTime;						// ���݂̎���
	DWORD oldTime = timeGetTime();			// �O�̎���

	ZeroMemory(&msg, sizeof(msg));
	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			currentTime = timeGetTime();
			if(currentTime - oldTime >= GAME_FPS)
			{
				if(pSceneManager->Run())
				{
					break;
				}
				oldTime = timeGetTime();
			}
		}
	}

	delete pSceneManager;
	GameLib::Instance().ReleaseGameLib();	// ���C�u�������̃������J��

	return (INT)msg.wParam;
}

//-----------------------------------------------------------------------------------------------------------//
//Functions
//-----------------------------------------------------------------------------------------------------------//

// �E�C���h�E�v���V�[�W���֐�
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return  0;
	}
	break;
	case WM_KEYDOWN:
		switch((CHAR)wparam)
		{
		case VK_ESCAPE:
		{
			int answer = MessageBox(hwnd, TEXT("�I���܂����H"), TEXT("�I��"), MB_YESNO);
			if(answer == IDYES)
			{
				PostQuitMessage(0);
				return 0;
			}
		}

		break;
		}
		break;

	case WM_SYSKEYDOWN:     // Alt + ����L�[�̏����Ɏg��
		switch((CHAR)wparam)
		{
		case VK_RETURN:     // Alt + Enter�������ƃE�B���h�E�؂�ւ�
			GameLib::Instance().ChangeWindowMode();
			break;
		default:
			break;
		}
		break;

	case WM_ACTIVATE:
		switch((CHAR)wparam)
		{
		case WA_ACTIVE:
		case WA_CLICKACTIVE:

			break;
		}
	}
	return  DefWindowProc(hwnd, message, wparam, lparam);
}
