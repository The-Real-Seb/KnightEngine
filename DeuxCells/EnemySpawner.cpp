#include "EnemySpawner.h"
#include "Enemy.h"
#include "EnemyMovement.h"

void EnemySpawner::Start()
{
	spawnCoolDown = 2.f;
	actualCD = spawnCoolDown;
}

void EnemySpawner::Update(float deltaTime)
{
	//std::cout << actualCD << std::endl;
	if (actualCD > 0) {
		actualCD -= deltaTime;
	}
	else {
		Spawn();
		actualCD = spawnCoolDown;
	}
}

void EnemySpawner::Spawn()
{
	if (spawnCoolDown > 0.1f) {
		spawnCoolDown -= 0.01f;
	}
	else {
		spawnCoolDown = 0.1f;
	}

	KE::Application* app = KE::Application::GetInstance();

	std::cout << "Spawn" << std::endl;
	KE::Entity* enemy = app->CreateSpecificEntity<Enemy>();
	enemy->Awake();
	enemy->Start();
	sf::Vector2f position;

	
	EnemyMovement* Emovement = app->GetComponent<EnemyMovement>(enemy);
	

	position.x = std::cos(std::rand()) * 300;
	position.y = std::sin(std::rand()) * 200;

	enemy->SetPosition(position);

	Emovement->Init();

	
}
