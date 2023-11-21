#pragma once
#include <KnightEngine/AComponent.h>
#include <KnightEngine/CRigidbody.h>

#include <KnightEngine/Entity.h>

class EnemyMovement : public KE::AComponent
{
protected:
	float speed = 50000000000000.0f;
	KE::CRigidbody* rb;
	sf::Vector2f direction;
	sf::Vector2f target;

public:
	EnemyMovement();
	~EnemyMovement();

	void Awake();
	void Update(float deltaTime);
};

