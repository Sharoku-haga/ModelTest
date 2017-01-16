/**
* @file		SceneFactory.h
* @brief	SceneFactoryクラスヘッダ
* @author	haga
*/
#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H

#include "Scene.h"

class SceneFactory
{

public:
	/**
	* 実体を取得する関数 
	* Singletonパターン
	* @return SceneFactory SceneFactoryクラスの実体 
	*/
	static SceneFactory& Instance()
	{
		static SceneFactory factory;

		return factory;
	}

	/**
	* Sceneクラスの継承クラスを生成する関数
	* @param	sceneID		生成したシーンのID
	* @param	Scene*		Sceneクラスのインスタンスへのポインタ
	*/
	Scene* CreateScene(Scene::ID  sceneID);

	/**デストラクタ*/
	~SceneFactory();

private:
	/**
	* コンストラクタ
	* Singletonパターンの為private
	*/
	SceneFactory();

};

#endif // SCENE_FACTORY_H
