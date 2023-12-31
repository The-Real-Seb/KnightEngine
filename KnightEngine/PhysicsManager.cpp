#include "PhysicsManager.h"
#include <iostream>
#include "Application.h"
#include "Entity.h"
#include "CRigidbody.h"
#include "Constants.h"


KE::PhysicsManager::PhysicsManager(): _gravity(0, 10.f), _world(_gravity)
{
	ColListener = new CollisionListener();
	_world.SetContactListener(ColListener);
	
}

KE::PhysicsManager::~PhysicsManager()
{

}

void KE::PhysicsManager::PhysicsUpdate(float deltaTime)
{	
	
	std::vector<Entity*> entities;
	entities = KE::Application::GetInstance()->GetAllEntities();

	for (Entity* entity : entities)
	{
		CRigidbody* rb = KE::Application::GetInstance()->GetComponent<CRigidbody>(entity);
		if (rb != nullptr) {
			
			rb->SetBodyPosition(b2Vec2(entity->getPosition().x / ppm, entity->getPosition().y / ppm));
		}		
	}
		
	_world.Step(deltaTime, _velocityIteration, _positionIteration);

	for (Entity* entity : entities)
	{
		CRigidbody* rb = KE::Application::GetInstance()->GetComponent<CRigidbody>(entity);
		if (rb != nullptr) {
			
			//std::cout << _world.DebugDraw() << std::endl;
			entity->setPosition(sf::Vector2(rb->GetBodyPosition().x * ppm, rb->GetBodyPosition().y * ppm));
			entity->setRotation(rb->GetBodyAngle());
			
		}
	}
}

b2World* KE::PhysicsManager::GetWorld()
{
	return &_world;
}

KE::CollisionListener* KE::PhysicsManager::GetListerner()
{
	return ColListener;
}

