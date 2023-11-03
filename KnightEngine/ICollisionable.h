#pragma once
#include "Collision.h"

namespace KE {
	class ICollisionable
	{
	public:
		virtual void BeginCollision(Collision* collision) = 0;
		virtual void EndCollision(Collision* collision) = 0;
	};
}


