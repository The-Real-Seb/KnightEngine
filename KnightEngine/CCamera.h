#pragma once
#include "AComponent.h"
#include "Application.h"
#include <SFML/Graphics.hpp>


namespace KE {
	class CCamera : public AComponent
	{
	protected:
		sf::View _view;		

	public:
		CCamera();
		~CCamera();

		void SetView(sf::FloatRect rect);
		void SetZoom(float value);
		void SetZoom(float width, float height);
		void SetViewport(sf::FloatRect rect);
		void SetRotation(float degree);
		void SetPosition(float x, float y);
		void SetPosition(sf::Vector2f);

		virtual void Awake() override;
		virtual void Update(float deltaTime) override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}


