#pragma once
#include "CCollider.h"
#include "box2d/b2_polygon_shape.h"

namespace KE {
	class CBoxCollider : public CCollider
	{
	protected:
		b2PolygonShape _shape;
		sf::Vector2f _size = sf::Vector2f();

	public:
		virtual b2Shape* GetShape() override;
		void SetSize(float sizeX, float sizeY);

		virtual void BeginCollision(Collision* collision) override;
		virtual void EndCollision(Collision* collision)override;
	};
}


