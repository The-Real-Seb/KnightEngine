#pragma once
#include <box2d/b2_fixture.h>

namespace KE {
	class Collision
	{
	protected:
		b2Fixture* _colliderA;
		b2Fixture* _colliderB;	

	public:
		Collision();
		bool isCollide;
		void SetColliderA(b2Fixture* col);
		void SetColliderB(b2Fixture* col);

		b2Fixture* GetColliderA();
		b2Fixture* GetColliderB();
	};
}


