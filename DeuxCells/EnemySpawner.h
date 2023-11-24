#pragma once
#include <KnightEngine/AComponent.h>

class EnemySpawner : public KE::AComponent
{
private : 
	float actualCD;

public:
	float spawnCoolDown;

	void Start();
	void Update(float deltaTime);

	void Spawn();

};

