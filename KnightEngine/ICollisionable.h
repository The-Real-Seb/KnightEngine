#pragma once
class Collision;
#include "Collision.h"

namespace KE {
	class ICollisionable
	{
	public:
		~ICollisionable() {}
		virtual void BeginCollision(KE::Collision* collision) = 0;
		virtual void EndCollision(KE::Collision* collision) = 0;
	};
}


