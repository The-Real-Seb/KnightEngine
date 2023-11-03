#include "CRigidbody.h"

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
