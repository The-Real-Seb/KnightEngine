#include "CBoxCollider.h"

b2Shape* KE::CBoxCollider::GetShape()
{
    _shape.SetAsBox(_size.x, _size.y);
    return &_shape;
}

void KE::CBoxCollider::SetSize(float sizeX, float sizeY)
{
    _size = sf::Vector2f(sizeX, sizeY);
}
