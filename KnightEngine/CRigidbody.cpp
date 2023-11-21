#include "CRigidbody.h"
#include "Application.h"
#define _USE_MATH_DEFINES
#include <math.h>

KE::CRigidbody::CRigidbody()
{
	_bodyDef.gravityScale = 1.0f;
	_body = KE::Application::GetInstance()->GetPhysicsManager()->GetWorld()->CreateBody(&_bodyDef);
}

KE::CRigidbody::~CRigidbody()
{
	
}

void KE::CRigidbody::SetBodyType(b2BodyType type)
{
	_body->SetType(type);
	_bodyDef.type = type;
}

void KE::CRigidbody::SetBodyPosition(b2Vec2 position)
{
	_bodyDef.position = position;
	_body->SetTransform(position, GetBodyAngle());
}

void KE::CRigidbody::SetLinearVelocity(b2Vec2 linearVelocity)
{
	_bodyDef.linearVelocity = linearVelocity;
	_body->SetLinearVelocity(linearVelocity);
}

void KE::CRigidbody::SetAngularVelocity(float angularVelocity)
{
	_bodyDef.angularVelocity = angularVelocity;
	_body->SetAngularVelocity(angularVelocity);
	
}

void KE::CRigidbody::SetGravityScale(float scale)
{
	_bodyDef.gravityScale = scale;
	_body->SetGravityScale(scale);
}

void KE::CRigidbody::SetLinearDamping(float damp)
{
	_body->SetLinearDamping(damp);
}

void KE::CRigidbody::SetAngularDamping(float damp)
{
	_body->SetAngularDamping(damp);
}

void KE::CRigidbody::LookAt(Entity* target)
{
	float angleWanted;
	float angleTarget;	

	Entity* parent = Application::GetInstance()->GetParent(this);
	sf::Vector2f forward = target->GetPosition() - parent->GetPosition();
	angleTarget = std::atan2(forward.y, forward.x);	

	angleWanted = (angleTarget * 180.0 / 3.141592653589793238463);

	_body->SetTransform(_body->GetTransform().p, angleWanted + 90);
}

void KE::CRigidbody::LookAt(sf::Vector2f target)
{
	float angleWanted;
	float angleTarget;

	Entity* parent = Application::GetInstance()->GetParent(this);
	sf::Vector2f forward = target - parent->GetPosition();
	angleTarget = std::atan2(forward.y, forward.x);

	angleWanted = (angleTarget * 180.0 / 3.141592653589793238463);

	_body->SetTransform(_body->GetTransform().p, angleWanted + 90);
}

float KE::CRigidbody::GetDistance(Entity* target)
{
	Entity* parent = KE::Application::GetInstance()->GetParent(this);

	float hypotenuse = std::sqrt((target->GetPosition().x - parent->GetPosition().x) + (target->GetPosition().y - parent->GetPosition().y));

	return hypotenuse;
}

sf::Vector2f KE::CRigidbody::GetForward(Entity* target)
{
	Entity* parent = Application::GetInstance()->GetParent(this);
	sf::Vector2f forward = target->GetPosition() - parent->GetPosition();

	return forward;
}

sf::Vector2f KE::CRigidbody::GetForward(sf::Vector2f target)
{
	Entity* parent = Application::GetInstance()->GetParent(this);

	sf::Vector2f forward = target - parent->GetPosition();

	return forward;
}

void KE::CRigidbody::ApplyImpulseToCenter(b2Vec2 linearImpulse)
{
	_body->ApplyLinearImpulseToCenter(linearImpulse, true);
}

void KE::CRigidbody::ApplyForceToCenter(b2Vec2 linearForce)
{
	_body->ApplyForceToCenter(linearForce, true);
}

b2Vec2 KE::CRigidbody::GetBodyPosition()
{
	return _body->GetPosition();
}

float KE::CRigidbody::GetBodyAngle()
{
	return _body->GetAngle();	
}

b2Vec2 KE::CRigidbody::GetLinearVelocity()
{
	return _body->GetLinearVelocity();
}

float KE::CRigidbody::GetAngularVelocity()
{
	return _body->GetAngularVelocity();
}

b2Body* KE::CRigidbody::GetBody()
{
	return _body;
}
