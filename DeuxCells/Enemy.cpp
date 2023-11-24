#include "Enemy.h"
#include "EnemyMovement.h"

Enemy::Enemy()
{
	appInstance = KE::Application::GetInstance();
	this->SetName("Enemy");
	this->setScale(sf::Vector2f(0.6f, 0.6f));

	rb = appInstance->AddComponent<KE::CRigidbody>(this);
	sprite = appInstance->AddComponent<KE::CSpriteRenderer>(this);
	collider = appInstance->AddComponent<KE::CBoxCollider>(this);
	appInstance->AddComponent<EnemyMovement>(this);

	sprite->SetSprite(
		false, 
		appInstance->GetRessourceManager()->GetAssetPath("arrow"), 
		sf::Color::White,
		this
	);	

	rb->SetBodyType(b2BodyType::b2_dynamicBody);
	rb->SetGravityScale(0);
	rb->SetLinearDamping(0.f);
	rb->GetBody()->SetBullet(true);
	//rb->SetAngularDamping(10000);	

	collider->SetDensity(0.1f);
	collider->SetSize(10,15);
	
	collider->SetFixture(rb->GetBody());
	collider->SetIsTrigger(true);
	

	this->SetPosition(sf::Vector2f(0, 0));	
}
