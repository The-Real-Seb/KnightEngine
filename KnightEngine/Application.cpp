#include <iostream>
#include "Application.h"
#include "AComponent.h"
#include "Entity.h"




int KE::Application::_genericID = 0;
KE::Application* KE::Application::_instance = nullptr;

KE::Application::Application()
{
	_instance = this;
	_ressourceManager = new RessourceManager();
	_physicsManager = new PhysicsManager();
}

KE::Application::~Application()
{
	for (Entity* entity : _entities) {
		delete entity;
	}
	for (AComponent* comp : _components) {
		delete comp;
	}
}

void KE::Application::Init()
{
	for (Entity* entity : _entities)
	{
		entity->Awake();
	}
}

void KE::Application::UpdateLoop()
{
	sf::Clock clock;
	while (_window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}

		_physicsManager->PhysicsUpdate(deltaTime);

		for (Entity* entity : _entities)
		{
			entity->Update(deltaTime);
		}

		_window.clear();

		for (Entity* entity : _entities)
		{
			entity->LateUpdate(deltaTime);
		}

		DrawEntities(_window);
		_window.display();
	}	
}

void KE::Application::Open()
{
	_window.create(sf::VideoMode(1280, 720), "MyWindow");
	
}

void KE::Application::Quit()
{
}

KE::Entity* KE::Application::CreateEntity()
{
	Entity* entity = new Entity();	
	_entities.push_back(entity);
	return entity;
}

KE::Entity* KE::Application::GetEntity(int id)
{
	for (Entity* entity : _entities) {
		if (entity->GetID() == id) {
			return entity;
		}		
	}
	return nullptr;
}

KE::Entity* KE::Application::GetParent(AComponent* comp)
{
	if (_link.contains(comp->GetID())) {
		for (Entity* entity : _entities)
		{
			if (_link.at(comp->GetID()) == entity->GetID()) {
				return entity;
			}
		}
	}

	return nullptr;
}

std::vector<KE::Entity*> KE::Application::GetAllEntities()
{
	return _entities;
}

std::vector<KE::AComponent*> KE::Application::GetAllComponents()
{
	return _components;
}


std::vector<KE::AComponent*> KE::Application::GetAllComponentsOf(KE::Entity* entity)
{
	std::vector<AComponent*> components;
	std::cout << "Number of components: " << _components.size() << std::endl;

	for (AComponent* component : _components) 
	{
		if (_link.at(component->GetID()) == entity->GetID()) {
			components.push_back(component);			
		}
	}
	return components;
}



KE::Application* KE::Application::GetInstance()
{
	if (!_instance) {
		_instance = new Application();
	}
	return _instance;
}

KE::RessourceManager* KE::Application::GetRessourceManager()
{
	return _ressourceManager;
}

KE::PhysicsManager* KE::Application::GetPhysicsManager()
{
	return _physicsManager;
}

void KE::Application::DrawEntities(sf::RenderTarget& target)
{
	for (Entity* entity : _entities)
	{
		target.draw(*entity);
	}
}

int KE::Application::GenerateID() {
	_genericID++;
	return _genericID;
}


