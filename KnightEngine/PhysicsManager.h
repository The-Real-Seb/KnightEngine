#pragma once
#include "box2d/b2_world.h"
#include "CollisionListener.h"

namespace KE {
	class PhysicsManager
	{
	protected:
		b2Vec2 _gravity;		
		int32 _velocityIteration = 8;
		int32 _positionIteration = 6;
		b2World _world;
		CollisionListener* ColListener;
		
	public:
		PhysicsManager();
		~PhysicsManager();		
		void PhysicsUpdate(float deltaTime);
		b2World* GetWorld();

		CollisionListener* GetListerner();
	};
}


