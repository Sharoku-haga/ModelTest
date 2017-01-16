/**
* @file		ObjectManager.h
* @brief	ObjectManagerクラスヘッダ
* @author	haga
*/

#ifndef OBJECT_MANAGER_H
#define OBJECT_MANAGER_H

#include <vector>

class Object;
class Collision;

/**
* Objectクラスを管理するクラス.
*/
class ObjectManager
{
public:
	/**コンストラクタ*/
	ObjectManager();

	/**dデストラクタ*/
	~ObjectManager();

	/**コントロール関数*/
	void Control();

	/**描画関数*/
	void Draw();

private:
	std::vector<Object*>	m_pObject;			//!< Objectクラスのインスタンスへのポインタの動的配列
	Collision*				m_pCollision;		//!< Collisionクラスのインスタンスへのポインタ
};

#endif	// OBJECT_MANAGER_H

