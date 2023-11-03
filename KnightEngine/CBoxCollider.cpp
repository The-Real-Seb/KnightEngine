#include "CBoxCollider.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

b2Shape* KE::CBoxCollider::GetShape()
{
    _shape.SetAsBox(_size.x, _size.y);
    return &_shape;
}

void KE::CBoxCollider::SetSize(float sizeX, float sizeY)
{
    _size = sf::Vector2f(sizeX, sizeY);
}

void KE::CBoxCollider::BeginCollision(Collision* collision)
{
    std::cout << "Begin Box Collision" << std::endl;
}

void KE::CBoxCollider::EndCollision(Collision* collision)
{
}
