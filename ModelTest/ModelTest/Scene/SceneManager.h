/**
* @file		SceneManager.h
* @brief	SceneManager�N���X�w�b�_ 
* @author	haga
*/
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"

class SceneManager
{

public:
	/**�R���X�g���N�^*/
	SceneManager();

	/**�f�X�g���N�^*/
	~SceneManager();

	/**���s�֐�*/
	bool Run();

private:
	/**�����X�e�b�v*/
	enum STEP
	{
		SCENE_CREATE,	// ����
		SCENE_RUN,		// ���s
		SCENE_DELETE	// �j��
	};

	Scene*      m_pScene;				//!< Scene�N���X�̃C���X�^���X�ւ̃|�C���^
	STEP		m_Step;					//!< �����X�e�b�v���i�[����ϐ�
	Scene::ID 	m_CurrentSceneID;		//!< ���݂̃V�[��ID���i�[����ϐ�
	Scene::ID 	m_NextSceneID;			//!< ���̃V�[��ID���i�[����ϐ�
	bool		m_IsEnd;				//!< �I���������ǂ����̃t���O

	/**�R���g���[���֐�*/
	void Control();

	/**�`��֐�*/
	void Draw();

};

#endif	// SCENE_MANAGER_H
