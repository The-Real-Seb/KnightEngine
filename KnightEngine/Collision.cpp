#include "Collision.h"

KE::Collision::Collision()
{
}

void KE::Collision::SetColliderA(b2Fixture* col)
{
	_colliderA = col;
}

void KE::Collision::SetColliderB(b2Fixture* col)
{
	_colliderB = col;
}

b2Fixture* KE::Collision::GetColliderA()
{
	return nullptr;
}

b2Fixture* KE::Collision::GetColliderB()
{
	return nullptr;
}
