#include "CollisionListener.h"
#include <box2d/box2d.h>
#include "Application.h"
#include "ICollisionable.h"
#include "Collision.h"
#include "CCollider.h"


void KE::CollisionListener::BeginContact(b2Contact* contact)
{
	Application* app = KE::Application::GetInstance();
	
	for (AComponent* comp : app->GetAllComponents())
	{		
		if (ICollisionable* convertedComp = dynamic_cast<ICollisionable*>(comp)) {

			if (CCollider* collider = dynamic_cast<CCollider*>(comp)) {

				Collision* collision = new Collision();				
				collision->isCollide = contact->IsTouching();

				if (collider->GetFixture()->GetBody() == contact->GetFixtureA()->GetBody() || collider->GetFixture()->GetBody() == contact->GetFixtureB()->GetBody()) {
					collision->SetColliderA(contact->GetFixtureA());
					collision->SetColliderB(contact->GetFixtureB());
					convertedComp->BeginCollision(collision);
				}	
			}
		}
	}
}

void KE::CollisionListener::EndContact(b2Contact* contact)
{
	Application* app = KE::Application::GetInstance();

	for (AComponent* comp : app->GetAllComponents())
	{
		if (ICollisionable* convertedComp = dynamic_cast<ICollisionable*>(comp)) {

			if (CCollider* collider = dynamic_cast<CCollider*>(comp)) {

				Collision* collision = new Collision();
				collision->isCollide = contact->IsTouching();

				if (collider->GetFixture()->GetBody() == contact->GetFixtureA()->GetBody() || collider->GetFixture()->GetBody() == contact->GetFixtureB()->GetBody()) {
					collision->SetColliderA(contact->GetFixtureA());
					collision->SetColliderB(contact->GetFixtureB());
					convertedComp->EndCollision(collision);
				}
			}
		}
	}
}
