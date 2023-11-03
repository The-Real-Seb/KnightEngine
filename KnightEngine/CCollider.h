#pragma once
#include "AComponent.h"
#include "box2d/b2_fixture.h"
#include "Collision.h"
#include "ICollisionable.h"


namespace KE {
	class CCollider : public AComponent, public ICollisionable
	{
	protected:
		b2Fixture* _fixture;
		b2FixtureDef _fixtureDef;
	public:
		virtual void SetFixture(b2Body* body);
		virtual b2Shape* GetShape();
		void SetDensity(float density);
		void SetFriction(float friction);
		
		virtual void BeginCollision(Collision* collision);		
		virtual void EndCollision(Collision* collision);
	};
}


