#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AComponent.h"
#include "RessourceManager.h"
#include "PhysicsManager.h"

namespace KE {
	class Application
	{
	protected:
		std::vector<Entity*> _entities;
		std::vector<AComponent*> _components;
		std::map<int, int> _link;

		static Application* _instance;
		static int _genericID;

		KE::RessourceManager* _ressourceManager;
		KE::PhysicsManager* _physicsManager;

	public:	
		sf::RenderWindow _window;
		Application();
		~Application();

		void Init();
		void UpdateLoop();
		void Open();
		void Quit();

		Entity* CreateEntity();
		Entity* GetEntity(int id);
		Entity* GetParent(AComponent* comp);
		std::vector<Entity*> GetAllEntities();

		template<typename T>
		T* AddComponent(Entity* entity);

		std::vector<AComponent*> GetAllComponentsOf(Entity* entity);

		template<typename T>
		T* GetComponent(Entity* entity);

		static Application* GetInstance();
		KE::RessourceManager* GetRessourceManager();
		KE::PhysicsManager* GetPhysicsManager();

		int GenerateID();

		void DrawEntities(sf::RenderTarget& target);
	};


	template<typename T>
	 T* KE::Application::AddComponent(KE::Entity* entity)
	{
		std::cout << "Adding component..." << std::endl;
		T* component = new T();
		_components.push_back(component);
		std::cout << _components.size() << std::endl;
		_link[component->GetID()] = entity->GetID();	

		return component;
	}

	template<typename T>
	T* KE::Application::GetComponent(Entity* entity)
	{
		for (AComponent* component : _components) {
			if (_link.at(component->GetID()) == entity->GetID()) {
				if (T* convertedComp = dynamic_cast<T*>(component)) {
					return convertedComp;
				}
			}			
		}
		return nullptr;
	}
}


