#include "ICollisionable.h"
#include "CCollider.h"
#include "Application.h"
#include "CRigidbody.h"
#include "Collision.h"
#include "CScriptLua.h"

void KE::CCollider::SetFixture(b2Body* body)
{
	//_fixture = body->CreateFixture(&_fixtureDef);
	b2Shape* shape = GetShape();	
	_fixture = body->CreateFixture(shape, _fixtureDef.density);
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

void KE::CCollider::SetIsTrigger(bool isTrigger)
{
	_fixtureDef.isSensor = isTrigger;
	_fixture->SetSensor(isTrigger);
}

b2Fixture* KE::CCollider::GetFixture()
{
	return _fixture;
}

void KE::CCollider::BeginCollision(Collision* collision)
{
	//std::cout << "Begin Collision" << std::endl;
	KE::Application* app = KE::Application::GetInstance();

	KE::CScriptLua* script = app->GetComponent<KE::CScriptLua>(app->GetParent(this));

	if (script) {
		script->BeginCollision();
	}
	
}

void KE::CCollider::EndCollision(Collision* collision)
{
	//std::cout << "End Collision" << std::endl;
	KE::Application* app = KE::Application::GetInstance();

	KE::CScriptLua* script = app->GetComponent<KE::CScriptLua>(app->GetParent(this));

	if (script) {
		script->EndCollision();
	}
}
