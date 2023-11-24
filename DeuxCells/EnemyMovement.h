#pragma once
#include <KnightEngine/AComponent.h>
#include <KnightEngine/CRigidbody.h>

#include <KnightEngine/Entity.h>

class EnemyMovement : public KE::AComponent
{
protected:
	float speed = 0;
	float lerpValue;

	KE::CRigidbody* rb;
	sf::Vector2f direction;
	sf::Vector2f target;

	float destroyDelay;
	float actualDelay;

public:
	EnemyMovement();
	~EnemyMovement();

	void Awake();
	void Init();
	void Update(float deltaTime);
};

