#pragma once
#include "CCollider.h"
namespace KE {
	class Collision
	{
	protected:
		CCollider* _colliderA;
		CCollider* _colliderB;
		bool isCollide;
	};
}


