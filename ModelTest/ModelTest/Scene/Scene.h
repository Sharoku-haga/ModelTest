/**
* @file		Scene.h
* @brief	Scene�N���X�w�b�_
* @author	haga
*/
#ifndef SCENE_H
#define SCENE_H

class GameLib;

/**
* �l�X�ȃV�[���̊��N���X
*/
class Scene
{

public:
	/**SCENE��ID*/
	enum ID
	{
		LOGO,			//!< ���S�V�[��
		TITLE,			//!< �^�C�g���V�[��
		GAME,			//!< �Q�[���V�[��
		TEST,			//!< �Փ˔���e�X�g�V�[��
		GAME_END
	};

	/**�R���X�g���N�^*/
	Scene();

	/**�f�X�g���N�^*/
	virtual~Scene();

	/**
	* �R���g���[���֐�
	* @return Scene::ID	���̃V�[����ID
	*/
	virtual Scene::ID Control() = 0;

	/**�`��֐�*/
	virtual void Draw() = 0;

protected:
	GameLib& m_rGameLib;		//!< ���C�u����

};

#endif // SCENE_H

