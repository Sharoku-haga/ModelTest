/**
* @file		SceneManager.cpp
* @brief	SceneManagerクラス実装
* @author	haga
*/

//----------------------------------------------------------------------------------------------------------//
//Includes
//----------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "SceneFactory.h"
#include "SceneManager.h"

//----------------------------------------------------------------------------------------------------------//
//Public functions
//----------------------------------------------------------------------------------------------------------//

SceneManager::SceneManager()
	: m_pScene(nullptr)
	, m_Step(SCENE_CREATE)
	, m_CurrentSceneID(Scene::ID::LOGO)
	, m_NextSceneID(Scene::ID::LOGO)
	, m_IsEnd(false)
{
#ifdef _DEBUG
	m_NextSceneID = Scene::ID::TEST;
#endif
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	m_pScene = nullptr;
}

bool SceneManager::Run()
{
	GameLib::Instance().UpdateDI();

	Control();

	GameLib::Instance().StartRender();

	Draw();

	GameLib::Instance().EndRender();

	return m_IsEnd;
}

//---------------------------------------------------------------------------------------------------------------//
//Private functions
//---------------------------------------------------------------------------------------------------------------//

void SceneManager::Control()
{
	switch(m_Step)
	{
	case SCENE_CREATE:
		m_CurrentSceneID = m_NextSceneID;
		if(m_CurrentSceneID == Scene::ID ::GAME_END)
		{
			m_IsEnd = true;
			return;
		}
		m_pScene = SceneFactory::Instance().CreateScene(m_CurrentSceneID);
		m_Step = SCENE_RUN;
		break;

	case SCENE_RUN:
		if(m_pScene != nullptr)
		{
			if(( m_NextSceneID = m_pScene->Control() ) != m_CurrentSceneID)
			{
				m_Step = SCENE_DELETE;
			}
		}
		else
		{	// シーンがつくられていなかったらゲームを終了する
			MessageBox(0, "シーン作成に失敗しています。", NULL, MB_OK);
			m_NextSceneID = Scene::ID::GAME_END;
			m_Step = SCENE_CREATE;
		}
		break;

	case SCENE_DELETE:
		delete m_pScene;
		m_pScene = nullptr;
		m_Step = SCENE_CREATE;
		break;
	}
}

void SceneManager::Draw()
{
	if (m_pScene != nullptr && m_Step == SCENE_RUN)
	{
		m_pScene->Draw();
	}
}
