
#include "CCircleShape.h"
#include "Application.h"

KE::CCircleShape::CCircleShape():AComponent()
{
	shape.setRadius(1);
}

void KE::CCircleShape::Awake()
{
	
}

void KE::CCircleShape::Update(float deltaTime)
{
	
}

void KE::CCircleShape::SetSize(float size)
{
	shape.setRadius(size);
}

void KE::CCircleShape::SetColor(sf::Color color)
{
	shape.setFillColor(color);
}

void KE::CCircleShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	target.draw(shape, states);
}

