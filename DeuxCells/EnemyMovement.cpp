#include "EnemyMovement.h"
#include <KnightEngine/Application.h>

EnemyMovement::EnemyMovement()
{
	KE::Application* app = KE::Application::GetInstance();
	target = app->GetEntityByName("player")->GetPosition();
	destroyDelay = 5;
	actualDelay = destroyDelay;
}

EnemyMovement::~EnemyMovement()
{
	//delete rb;	
}

void EnemyMovement::Awake()
{
	Init();	
}

void EnemyMovement::Update(float deltaTime)
{
	if (lerpValue < 1) {
		lerpValue += deltaTime * 0.85f;
	}	
	
	float c1 = 1.70158;
	float c3 = c1 + 1;

	//speed = std::lerp(0.f, 100.f, c3 * lerpValue * lerpValue * lerpValue - c1 * lerpValue * lerpValue);
	
	speed = std::lerp(0.f, 100.f, std::pow(2, 10.f * lerpValue - 10.f));

	sf::Vector2f tempDirection = direction * speed;

	b2Vec2 vect = b2Vec2(tempDirection.x * deltaTime, tempDirection.y * deltaTime);

	rb->SetLinearVelocity(vect);
	
	if (actualDelay > 0) {
		actualDelay -= deltaTime;
	}
	else {

		KE::Application* app = KE::Application::GetInstance();
		app->DestroyEntity(*app->GetParent(this));
	}	
}

void EnemyMovement::Init()
{
	KE::Application* app = KE::Application::GetInstance();
	rb = app->GetComponent<KE::CRigidbody>(app->GetParent(this));

	rb->LookAt(target);

	direction = rb->GetForward(target);

	float length = sqrt((direction.x * direction.x) + (direction.y * direction.y));
	if (length != 0) {
		direction.x = (direction.x * 100) / length;
		direction.y = (direction.y * 100) / length;
	}
	
}
