#pragma once
#include "box2d/b2_world_callbacks.h"

namespace KE {
	class CollisionListener : public b2ContactListener
	{
	public:
		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);
		
	};
}


