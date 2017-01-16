/**
* @file		TitleScene.h
* @brief	TitleSceneクラスヘッダ
* @author	haga
*/

#ifndef TITLE_SCENE_H
#define	TITLE_SCENE_H

#include "../Scene.h"

class TitleBackground;
class Button;

/**
* タイトルシーン
*/
class TitleScene :	public Scene
{

public:
	/**TextureID*/
	enum TEX_ID
	{
		TITLE_BACKGROUND,		//!< 背景
		PUSH_BUTTON,			//!< ボタン
	};

	/**VertexID*/
	enum VTX_ID
	{
		BACKGROUND,				//!< 背景
		PUSH_BTN,				//!< ボタン
	};

	/**タイトルの状態*/
	enum STATE
	{
		FADE_IN,				//!< フェードイン
		WAIT_PUSH_BUTTON,		//!< ボタン押し待ち画面
		FADE_OUT,				//!< フェードアウト
		NEXT_SCENE,				//!< 次のシーンへ移行
	};

	/**コンストラクタ*/
	TitleScene();

	/**デストラクタ*/
	virtual ~TitleScene();

	/**
	* コントロール関数
	* @return Scene::ID	次のシーンのID
	*/
	virtual Scene::ID Control()override;

	/**描画関数*/
	virtual void Draw()override;

private:
	TitleBackground*	m_pBackground;			//!< TitleBackgroundクラスのインスタンスへのポインタ
	Button*				m_pButton;				//!< Buttonクラスのインスタンスへのポインタ
	Scene::ID			m_NextScene;			//!< 次のシーンIDを格納する変数
	TitleScene::STATE	m_State;				//1< タイトルシーンの状態

};

#endif	// TITLE_SCENE_H
