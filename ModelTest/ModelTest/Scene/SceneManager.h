/**
* @file		SceneManager.h
* @brief	SceneManagerクラスヘッダ 
* @author	haga
*/
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

class SceneManager
{

public:
	/**コンストラクタ*/
	SceneManager();

	/**デストラクタ*/
	~SceneManager();

	/**実行関数*/
	bool Run();

private:
	/**処理ステップ*/
	enum STEP
	{
		SCENE_CREATE,	// 生成
		SCENE_RUN,		// 実行
		SCENE_DELETE	// 破棄
	};

	Scene*      m_pScene;				//!< Sceneクラスのインスタンスへのポインタ
	STEP		m_Step;					//!< 処理ステップを格納する変数
	Scene::ID 	m_CurrentSceneID;		//!< 現在のシーンIDを格納する変数
	Scene::ID 	m_NextSceneID;			//!< 次のシーンIDを格納する変数
	bool		m_IsEnd;				//!< 終了したかどうかのフラグ

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

};

#endif	// SCENE_MANAGER_H
