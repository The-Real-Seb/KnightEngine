#pragma once
#include "AComponent.h"
#include <SFML/Graphics.hpp>

namespace KE {
	class CCircleShape : public AComponent, public sf::Drawable
	{
	protected:		
		sf::CircleShape shape;
		
	public:		

		CCircleShape();
		virtual void Awake() override;
		virtual void Update(float deltaTime) override;

		void SetSize(float size);
		void SetColor(sf::Color);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
