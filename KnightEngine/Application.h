#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "AComponent.h"
#include "RessourceManager.h"
#include "PhysicsManager.h"
#include "CRigidbody.h"
#include "LuaKeyboard.h"

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
		KE::LuaKeyboard* luaKeyboard;
		
		sf::RenderWindow _window;

		Application();
		~Application();

		void Init();
		void UpdateLoop();
		void Open();
		void Quit();

		template<typename T>
		T* CreateSpecificEntity();

		Entity* CreateEntity();

		Entity* GetEntity(int id);
		Entity* GetEntityByName(std::string name);
		Entity* GetParent(AComponent* comp);
		std::vector<Entity*> GetAllEntities();
		std::vector<AComponent*> GetAllComponents();		

		template<typename T>
		T* AddComponent(Entity* entity);

		std::vector<AComponent*> GetAllComponentsOf(Entity* entity);

		template<typename T>
		T* GetComponent(Entity* entity);

		static Application* GetInstance();	

#pragma region Wrapper
		CRigidbody* GetRigiBodyComponent(Entity* entity);
		
#pragma endregion Wrapper

		KE::RessourceManager* GetRessourceManager();
		KE::PhysicsManager* GetPhysicsManager();

		int GenerateID();

		void DrawEntities(sf::RenderTarget& target);
	};
	
	template<typename T>
	T* KE::Application::CreateSpecificEntity()
	{
		T* entity = new T();
		_entities.push_back(entity);
		return entity;
	}

	template<typename T>
	 T* KE::Application::AddComponent(KE::Entity* entity)
	{		
		T* component = new T();
		_components.push_back(component);		
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


