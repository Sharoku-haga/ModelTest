/**
* @file		FieldManager.h
* @brief	FieldManagerクラスヘッダ
* @author	haga
*/

#ifndef FIELD_MANAGER_H
#define FIELD_MANAGER_H

class Field;

/**
* Fieldクラスを管理するクラス
*/
class FieldManager
{

public:
	FieldManager();
	~FieldManager();

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

private:
	Field*		m_pField;		//!< Fieldクラスのインスタンスへのポインタ

};

#endif	// FIELD_MANAGER_H
