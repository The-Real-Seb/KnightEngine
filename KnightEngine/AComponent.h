#pragma once
#include <SFML/Graphics.hpp>

namespace KE {
	class AComponent
	{
	protected: 
		int _id;	

	public:
		AComponent();
		virtual void Awake();
		virtual void Start();
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);		

		int GetID();
	};
}


