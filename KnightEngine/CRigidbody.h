#pragma once
#include "box2d/b2_body.h"
#include "Application.h"

namespace KE {
	class CRigidbody : public AComponent
	{
	protected:
		b2Body* _body;
		b2BodyDef _bodyDef;

	public:
		CRigidbody();
		~CRigidbody();

		void SetBodyType(b2BodyType type);
		void SetBodyPosition(b2Vec2 position);
		void SetLinearVelocity(b2Vec2 linearVelocity);
		void SetAngularVelocity(float angularVelocity);

		b2Vec2 GetBodyPosition();
		float GetBodyAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();
	};
}


