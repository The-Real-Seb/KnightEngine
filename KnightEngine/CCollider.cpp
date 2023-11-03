#include "CCollider.h"
#include "Application.h"
#include "CRigidbody.h"

void KE::CCollider::SetFixture(b2Body* body)
{
	//_fixture = body->CreateFixture(&_fixtureDef);
	b2Shape* shape = GetShape();
	body->CreateFixture(shape, _fixtureDef.density);
}

b2Shape* KE::CCollider::GetShape()
{
	return nullptr;
}

void KE::CCollider::SetDensity(float density)
{
	_fixtureDef.density = density;
}

void KE::CCollider::SetFriction(float friction)
{
	_fixtureDef.friction = friction;
}
