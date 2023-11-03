#include "CollisionListener.h"
#include <box2d/box2d.h>
#include "Application.h"
#include "ICollisionable.h"
#include "Collision.h"


void KE::CollisionListener::BeginContact(b2Contact* contact)
{
	Application* app = KE::Application::GetInstance();

	for (AComponent* comp : app->GetAllComponents()) 
	{
		if (ICollisionable* convertedComp = dynamic_cast<ICollisionable*>(comp)) {

			Collision* collision = new Collision();
			collision->SetColliderA(contact->GetFixtureA());
			collision->SetColliderB(contact->GetFixtureB());
			collision->isCollide = contact->IsTouching();

			convertedComp->BeginCollision(collision);
		}
	}
}

void KE::CollisionListener::EndContact(b2Contact* contact)
{
	Application* app = KE::Application::GetInstance();

	for (AComponent* comp : app->GetAllComponents())
	{
		if (ICollisionable* convertedComp = dynamic_cast<ICollisionable*>(comp)) {

			Collision* collision = new Collision();
			collision->SetColliderA(contact->GetFixtureA());
			collision->SetColliderB(contact->GetFixtureB());
			collision->isCollide = contact->IsTouching();

			convertedComp->EndCollision(collision);
		}
	}
}
