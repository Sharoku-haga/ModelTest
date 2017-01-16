/**
* @file		SceneFactory.h
* @brief	SceneFactory�N���X�w�b�_
* @author	haga
*/
#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H

#include "Scene.h"

class SceneFactory
{

public:
	/**
	* ���̂��擾����֐� 
	* Singleton�p�^�[��
	* @return SceneFactory SceneFactory�N���X�̎��� 
	*/
	static SceneFactory& Instance()
	{
		static SceneFactory factory;

		return factory;
	}

	/**
	* Scene�N���X�̌p���N���X�𐶐�����֐�
	* @param	sceneID		���������V�[����ID
	* @param	Scene*		Scene�N���X�̃C���X�^���X�ւ̃|�C���^
	*/
	Scene* CreateScene(Scene::ID  sceneID);

	/**�f�X�g���N�^*/
	~SceneFactory();

private:
	/**
	* �R���X�g���N�^
	* Singleton�p�^�[���̈�private
	*/
	SceneFactory();

};

#endif // SCENE_FACTORY_H
