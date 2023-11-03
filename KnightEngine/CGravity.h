#pragma once
#include "AComponent.h"

namespace KE {
	class CGravity : public AComponent
	{
	private:
		sf::Vector2f _velocity;		

	public:
		CGravity();
		void SetVelocity(float _x, float _y);
		void SetVelocity(sf::Vector2f vector);

		virtual void Awake() override;
		virtual void Update(float deltaTime) override;
		
	};
}


