/**
* @file		PushOnlyButton.h
* @brief	PushOnlyButton�N���X�w�b�_
* @author	haga
*/

#ifndef PUSH_ONLY_BUTTON_H
#define	PUSH_ONLY_BUTTON_H	

#include "Button.h"

/**
* ���������̃{�^���̃N���X
*/
class PushOnlyButton :public Button
{

public:
	/**
	* �R���X�g���N�^.
	* @param	width	����
	* @param	height	����
	* @param	pos		�ʒu���W
	* @param	texID	�e�N�X�`���[ID
	* @param	vtxID	�o�[�e�b�N�XID
	*/
	PushOnlyButton(float width, float height, D3DXVECTOR2 pos, int texID, int vtxID);
	virtual ~PushOnlyButton();

	/**�R���g���[���֐�*/
	virtual void Control()override;

	/**�`��֐�*/
	virtual void Draw()override;

private:
	BYTE		m_Alpha;			//!< �A���t�@�l
	bool		m_IsFadeIn;			//!< FadeIn���ǂ����Btrue��FadeIn,false��FadeOut

	/**�t�F�[�h�C���A�t�F�[�h�A�E�g���s���֐�*/
	void FadeInOut();

};

#endif	// PUSH_ONLY_BUTTON_H
