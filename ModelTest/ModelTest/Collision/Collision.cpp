/**
* @file		Collision.cpp
* @brief	Collisionクラス実装
* @author	haga
*/

//------------------------------------------------------------------------------------------------------------//
//Includes
//------------------------------------------------------------------------------------------------------------//

#include "../Object/Object.h"
#include "Collision.h"

//------------------------------------------------------------------------------------------------------------//
//Public functions
//------------------------------------------------------------------------------------------------------------//

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::SetObject(std::vector<Object*> pObject)
{
	m_pObject.clear();
	m_pObject = pObject;
}

void Collision::CheckCollision()
{
	if(!m_pObject.empty())
	{
		for(unsigned int i = 0; i < ( m_pObject.size() - 1 ); i++)
		{
			for(unsigned  int j = 1; j < m_pObject.size(); j++)
			{
				if(m_pObject[i] == m_pObject[j])
				{
					continue;
				}

				D3DXVECTOR3 vecLength = ( m_pObject[j]->GetPos() ) - ( m_pObject[i]->GetPos() );
				float fLength = D3DXVec3Length(&vecLength);
				float radius = ( m_pObject[i]->GetRadius() ) + ( m_pObject[j]->GetRadius() );
				if(fLength < radius)
				{
					m_pObject[i]->InformCollision();
					m_pObject[j]->InformCollision();
				}
			}
		
		}
	}
}

