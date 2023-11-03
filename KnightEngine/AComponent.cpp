
#include "AComponent.h"
#include <iostream>
#include "Application.h"

KE::AComponent::AComponent()
{
	_id = KE::Application::GetInstance()->GenerateID();
}

void KE::AComponent::Awake()
{
	
}

void KE::AComponent::Start()
{
}

void KE::AComponent::Update(float deltaTime)
{
}

void KE::AComponent::LateUpdate(float deltaTime)
{
}

int KE::AComponent::GetID()
{
	return _id;
}


