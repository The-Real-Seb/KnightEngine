#include "EnemyMovement.h"
#include <KnightEngine/Application.h>

EnemyMovement::EnemyMovement()
{
	KE::Application* app = KE::Application::GetInstance();
	target = app->GetEntityByName("player")->GetPosition();
}

EnemyMovement::~EnemyMovement()
{
	//delete rb;	
}

void EnemyMovement::Awake()
{
	KE::Application* app = KE::Application::GetInstance();
	rb = app->GetComponent<KE::CRigidbody>(app->GetParent(this));	

	rb->LookAt(target);

	direction = rb->GetForward(target) * speed;
	
}

void EnemyMovement::Update(float deltaTime)
{
	b2Vec2 vect = b2Vec2(direction.x * deltaTime, direction.y * deltaTime);
	rb->SetLinearVelocity(vect);
}
