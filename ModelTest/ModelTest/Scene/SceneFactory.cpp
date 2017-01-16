/**
* @file		SceneFactory.cpp
* @brief	SceneFactoryƒNƒ‰ƒXŽÀ‘•
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "SceneFactory.h"
#include "LogoScene/LogoScene.h"
#include "TitleScene/TitleScene.h"
#include "TestScene/TestScene.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

Scene* SceneFactory::CreateScene(Scene::ID  sceneID)
{
	Scene* pScene = nullptr;

	switch (sceneID)
	{
	case Scene::ID::LOGO :
		pScene = new LogoScene();
		break;

	case Scene::ID::TITLE :
		pScene = new TitleScene();
		break;

	case Scene::ID::GAME :
		break;

	case Scene::ID::TEST :
		pScene = new TestScene();
		break;

	case Scene::ID::GAME_END :
		break;

	default:
		break;
	}

	return pScene;
}

SceneFactory::~SceneFactory()
{
}

//------------------------------------------------------------------------------------------------------------//
//Private functions
//------------------------------------------------------------------------------------------------------------//

SceneFactory::SceneFactory()
{
}
