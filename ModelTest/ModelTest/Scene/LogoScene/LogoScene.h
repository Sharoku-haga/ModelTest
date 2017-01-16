/**
* @file		LogoScene.h
* @brief	LogoSceneクラスヘッダ
* @author	haga
*/

#ifndef LOGO_SCENE_H
#define LOGO_SCENE_H

#include "../Scene.h"

class TeamLogo;

/**
* ロゴを管理するシーン.
*/
class LogoScene :public Scene
{

public:

	/**TextureID*/
	enum TEX_ID
	{
		LOGO,		//!< ロゴ
	};

	/**VertexID*/
	enum VTX_ID
	{
		TEAM_LOGO,	//!< ロゴ
	};

	/**コンストラクタ*/
	LogoScene();

	/**デストラクタ*/
	virtual ~LogoScene();

	/**
	* コントロール関数
	* @return Scene::ID	次のシーンのID
	*/
	virtual Scene::ID  Control() override;

	/**描画関数*/
	virtual void Draw() override;

private:
	TeamLogo*	m_pTeamLogo;		//!< TeamLogoクラスのインスタンスへのポインタ

};

#endif	// LOGO_SCENE_H
