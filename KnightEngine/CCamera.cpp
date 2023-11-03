#include "CCamera.h"

KE::CCamera::CCamera():KE::AComponent()
{
	_view.reset(sf::FloatRect(200, 200, 300, 200));
}

KE::CCamera::~CCamera()
{
	delete &_view;
}

void KE::CCamera::SetView(sf::FloatRect rect)
{
	_view.reset(rect);
}

void KE::CCamera::SetZoom(float value)
{
	_view.zoom(value);
}

void KE::CCamera::SetZoom(float width, float height)
{
	_view.setSize(width, height);
}

void KE::CCamera::SetViewport(sf::FloatRect rect)
{
	_view.setViewport(rect);
}

void KE::CCamera::SetRotation(float degree)
{
	_view.setRotation(degree);
}

void KE::CCamera::SetPosition(float x, float y)
{
	_view.setCenter(x, y);
}

void KE::CCamera::SetPosition(sf::Vector2f position)
{
	_view.setCenter(position.x, position.y);
}

void KE::CCamera::Awake()
{
	
}

void KE::CCamera::Update(float deltaTime)
{
	SetPosition(KE::Application::GetInstance()->GetParent(this)->getPosition());
	SetRotation(KE::Application::GetInstance()->GetParent(this)->getRotation());
	KE::Application::GetInstance()->_window.setView(_view);
}

void KE::CCamera::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
