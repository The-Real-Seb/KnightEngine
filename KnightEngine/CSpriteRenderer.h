#pragma once
#include "AComponent.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace KE {
	class CSpriteRenderer : public AComponent, public sf::Sprite
	{
	protected: 
		sf::Sprite _sprite;
		sf::Texture _texture;

	public:
		CSpriteRenderer();
		~CSpriteRenderer();

		void SetSprite();
		void SetSprite(bool isSmooth, std::string path, sf::Color color);
		void SetSprite(bool isSmooth, std::string path, sf::Color color, KE::Entity* entity);

		void SetTexture(std::string path);
		void SetColor(sf::Color color);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}


