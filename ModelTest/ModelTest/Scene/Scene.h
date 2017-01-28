/**
* @file		Scene.h
* @brief	Sceneクラスヘッダ
* @author	haga
*/
#ifndef SCENE_H
#define SCENE_H

class GameLib;

/**
* 様々なシーンの基底クラス
*/
class Scene
{

public:
	/**SCENEのID*/
	enum ID
	{
		LOGO,			//!< ロゴシーン
		TITLE,			//!< タイトルシーン
		GAME,			//!< ゲームシーン
		TEST,			//!< 衝突判定テストシーン
		GAME_END
	};

	/**コンストラクタ*/
	Scene();

	/**デストラクタ*/
	virtual~Scene();

	/**
	* コントロール関数
	* @return Scene::ID	次のシーンのID
	*/
	virtual Scene::ID Control() = 0;

	/**描画関数*/
	virtual void Draw() = 0;

protected:
	GameLib& m_rGameLib;		//!< ライブラリ

};

#endif // SCENE_H

