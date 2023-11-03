
#include "Entity.h"
#include "Application.h"

KE::Entity::Entity()
{	
	_id = KE::Application::GetInstance()->GenerateID();
}

sf::Vector2f KE::Entity::GetPosition()
{
	return getPosition();
}

void KE::Entity::SetPosition(sf::Vector2f position)
{
	setPosition(position);
}

void KE::Entity::Awake()
{	
	components = KE::Application::GetInstance()->GetAllComponentsOf(this);
	for (AComponent* component : components) {
		component->Awake();
	}
}

void KE::Entity::Start()
{
	if (!components.empty()) {
		for (AComponent* component : components) {
			component->Start();
		}
	}
}

void KE::Entity::Update(float deltaTime)
{
	if (!components.empty()) {
		for (AComponent* component : components) {
			component->Update(deltaTime);
		}
	}
}

void KE::Entity::LateUpdate(float deltaTime)
{
	KE::Application* app = KE::Application::GetInstance();
	if (!components.empty()) {
		for (AComponent* component : components) {
			component->LateUpdate(deltaTime);
		}
	}
}

void KE::Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	states.transform.combine(this->getTransform());

	for (AComponent* component : components) {	
		sf::Drawable* drawableComp = dynamic_cast<sf::Drawable*>(component);
		if (drawableComp != nullptr) {
			target.draw(*drawableComp, states);
		}			
	}	
}

void KE::Entity::SetName(std::string name)
{
	_name = name;	
}

int KE::Entity::GetID()
{
	return _id;
}

std::string KE::Entity::GetName()
{
	return _name;
}






