/**
* @file		LogoScene.cpp
* @brief	LogoSceneクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "GameLib/GameLib.h"
#include "LogoScene.h"
#include "TeamLogo.h"

//-----------------------------------------------------------------------------------------------------------//
//Public functions
//-----------------------------------------------------------------------------------------------------------//

LogoScene::LogoScene()
	: m_pTeamLogo(new TeamLogo())
{
	m_rGameLib.LoadTexEx(TEX_ID::LOGO,"../Resource/MyLogo.png", 255, 0, 0, 0, false);
}

LogoScene::~LogoScene()
{
	delete m_pTeamLogo;
	m_rGameLib.ReleaseTex(true);
	m_rGameLib.ReleaseVtx(true);
}

Scene::ID  LogoScene::Control()
{
	if(m_pTeamLogo->Control())
	{
		return Scene::ID::TITLE;
	}

	if(GameLib::Instance().ChecKMouseL() == ON ||
		GameLib::Instance().CheckKey(DIK_Z,Z) == ON)
	{
		return Scene::ID::TITLE;
	}

	return Scene::ID::LOGO;
}

void LogoScene::Draw()
{
	m_pTeamLogo->Draw();
}
