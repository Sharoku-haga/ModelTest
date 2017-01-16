/**
* @file		Collision.h
* @brief	Collisionクラスヘッダ
* @author	haga
*/

#ifndef COLLISION_H
#define COLLISION_H

#include <vector>

class Object;

/**
* 衝突判定を行うクラス
*/
class Collision
{

public:
	Collision();
	~Collision();

	/**
	* オブジェクト情報をセットする関数
	* @param	object	判定するオブジェクト群
	*/
	void SetObject(std::vector<Object*> pObject);
	
	/**s衝突判定を行う関数*/
	void CheckCollision();

private:
	std::vector<Object*>	m_pObject;		//!< 衝突判定するObjectクラスのインスタンスへのポインタの動的配列 

};

#endif	// COLLISION_H
