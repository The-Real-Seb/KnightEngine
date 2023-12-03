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
	luaKeyboard = new LuaKeyboard();
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
		entity->Start();
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
			luaKeyboard->AddEvent(event);
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}

		_physicsManager->PhysicsUpdate(deltaTime);

		for (int i = 0; i < _entities.size(); ++i)
		{
			Entity* entity = _entities[i];
			entity->Update(deltaTime);
		}

		_window.clear();

		for (Entity* entity : _entities)
		{
			entity->LateUpdate(deltaTime);
		}

		DrawEntities(_window);
		_window.display();
		luaKeyboard->Clear();
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

KE::Entity* KE::Application::GetEntityByName(std::string name)
{
	for (Entity* entity : _entities) {
		if (entity->GetName() == name) {
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


void KE::Application::DestroyEntity(Entity entityD)
{
	for (auto it = _entities.begin(); it != _entities.end(); )
	{
		if ((*it)->GetID() == entityD.GetID())
		{
			for (auto compIt = _components.begin(); compIt != _components.end(); )
			{
				if (_link.at((*compIt)->GetID()) == (*it)->GetID())
				{
					delete* compIt;
					compIt = _components.erase(compIt);
				}
				else
				{
					++compIt;
				}
			}			
			delete* it;
			it = _entities.erase(it);
		}
		else
		{
			++it;
		}
	}

	
}

void KE::Application::DestroyComponent(AComponent*)
{
}

std::vector<KE::AComponent*> KE::Application::GetAllComponentsOf(KE::Entity* entity)
{
	std::vector<AComponent*> components;	

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

KE::CRigidbody* KE::Application::GetRigiBodyComponent(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
	return GetComponent<KE::CRigidbody>(entity);
}

KE::CText* KE::Application::GetTextComponent(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
	return GetComponent<KE::CText>(entity);
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


