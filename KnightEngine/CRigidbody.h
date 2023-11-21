#pragma once
#include "box2d/b2_body.h"
#include "AComponent.h"
#include "Entity.h"

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

		void SetGravityScale(float scale);
		void SetLinearDamping(float damp);
		void SetAngularDamping(float damp);

		void LookAt(Entity* target);
		void LookAt(sf::Vector2f target);

		float GetDistance(Entity* target);

		sf::Vector2f GetForward(Entity* target);
		sf::Vector2f GetForward(sf::Vector2f target);

		void ApplyImpulseToCenter(b2Vec2 linearImpulse);
		void ApplyForceToCenter(b2Vec2 linearForce);

		b2Vec2 GetBodyPosition();
		float GetBodyAngle();
		b2Vec2 GetLinearVelocity();
		float GetAngularVelocity();
		b2Body* GetBody();
	};
}


