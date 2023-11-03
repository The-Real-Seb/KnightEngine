#include <iostream>
#include "CGravity.h"
#include "Application.h"

KE::CGravity::CGravity():AComponent()
{	
	
}

void KE::CGravity::SetVelocity(float _x, float _y)
{
	_velocity.x = _x;
	_velocity.y = _y;
}

void KE::CGravity::SetVelocity(sf::Vector2f vector)
{
	_velocity = vector;
}

void KE::CGravity::Awake()
{
	
}

void KE::CGravity::Update(float deltaTime)
{	
	KE::Application::GetInstance()->GetParent(this)->move(_velocity);
}

