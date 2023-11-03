#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AComponent.h"


namespace KE {
	class Entity : public sf::Transformable, public sf::Drawable
	{
	protected:
		int _id;
		std::string _name;
	public:
		
		std::vector<AComponent*> components;

		void Awake();
		void Start();
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);
		void SetName(std::string name);

		int GetID();
		std::string GetName();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		Entity();
	};
}


