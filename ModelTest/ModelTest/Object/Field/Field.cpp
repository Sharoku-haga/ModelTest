﻿/**
* @file		Field.cpp
* @brief	Fieldクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "Field.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

Field::Field(D3DXVECTOR3 pos, float angle, int xFileID)
	: Object(pos, angle, xFileID)
{
}

Field::~Field()
{
}

