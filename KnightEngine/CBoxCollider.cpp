#include "CBoxCollider.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "PhysicsManager.h"

b2Shape* KE::CBoxCollider::GetShape()
{
    _shape.SetAsBox(_size.x, _size.y);
    return &_shape;
}

void KE::CBoxCollider::SetSize(float sizeX, float sizeY)
{
    _size = sf::Vector2f(sizeX / PhysicsManager::ppm, sizeY / PhysicsManager::ppm);
}

void KE::CBoxCollider::BeginCollision(Collision* collision)
{    
    CCollider::BeginCollision(collision);
}

void KE::CBoxCollider::EndCollision(Collision* collision)
{
    CCollider::EndCollision(collision);
}
