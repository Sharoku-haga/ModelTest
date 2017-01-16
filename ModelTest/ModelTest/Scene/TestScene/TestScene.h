/**
* @file		TestScene.h
* @brief	TestSceneクラスヘッダ
* @author	haga
*/

#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "../Scene.h"

class ObjectManager;
class FieldManager;

/**
* 衝突判定テストを行うシーン
*/
class TestScene :public Scene
{

public:
	/**ModeID*/
	enum MODE
	{
		NOMAL_MODE,		//!< 通常モード
		CAMERA_MODE,	//!< カメラモード
		ROTATION_MODE,	//!< 回転モード
	};

	/**TextureID*/
	enum TEX_ID
	{
		EXPLOSION_TEX,		//!< 爆発エフェクト
	};

	/**VertexID*/
	enum VTX_ID
	{
		EXPLOSION_VTX,		//!< 爆発エフェクト
	};

	/**XFileID*/
	enum XFILE_ID
	{
		PLAYER,				//!< プレイヤーモデル
		GROUND,				//!< 地面モデル
		CHIPS,				//!< チップスの袋
	};

	/**コンストラクタ*/
	TestScene();

	/**dデストラクタ*/
	virtual ~TestScene();

	/**
	* コントロール関数
	* @return Scene::ID	シーンID
	*/
	virtual Scene::ID	Control() override;

	/**描画関数*/
	virtual void		Draw() override;

private:
	ObjectManager*		m_pObjectManager;				//!< ObjectManagerクラスのインスタンスへのポインタ
	FieldManager*		m_pFieldManager;				//!< FieldManagerクラスのインスタンスへのポインタ
	MODE				m_CourrentMode;					//!< 現在のモードを格納する変数

};

#endif
