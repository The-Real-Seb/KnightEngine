//#include <SFML/Graphics.hpp>
#include <KnightEngine/AComponent.h>
#include <KnightEngine/Entity.h>
#include <KnightEngine/CCircleShape.h>
#include <KnightEngine/CSpriteRenderer.h>
#include <KnightEngine/CCamera.h>
#include <KnightEngine/CRigidbody.h>
#include <KnightEngine/CBoxCollider.h>
#include <KnightEngine/CCollider.h>
#include <KnightEngine/Application.h>
#include <KnightEngine/CScriptLua.h>
#include <KnightEngine/CText.h>
#include "Enemy.h"
#include "EnemySpawner.h"

int main()
{
	KE::Application* app = new KE::Application();
    app->Open();

	KE::Entity* rect = app->CreateEntity();
	rect->SetName("rect");
	rect->setPosition(0, 0);
	KE::CSpriteRenderer* rectSprite = app->AddComponent<KE::CSpriteRenderer>(rect);
	rectSprite->SetSprite(false, app->GetRessourceManager()->GetAssetPath("rect"), sf::Color::White);
	rect->setScale(sf::Vector2f(2.0f, 2.0f));

	KE::Entity* player = app->CreateEntity();
	player->SetName("player");
	player->setPosition(0, 0);
	
	KE::Entity* score = app->CreateEntity();
	score->SetName("score");
	score->setPosition(0, 0);
	score->setScale(sf::Vector2f(2.0f, 2.0f));

	KE::CText* textComp = app->AddComponent<KE::CText>(score);
	textComp->SetFont(app->GetRessourceManager()->GetAssetPath("fipps"));
	std::cout << app->GetRessourceManager()->GetAssetPath("fipps") << std::endl;
	textComp->SetString("Hello");
	textComp->SetFillColor(sf::Color::White);
	textComp->SetSize(5);
	

	KE::CSpriteRenderer* cSpriteRenderer = app->AddComponent<KE::CSpriteRenderer>(player);
	//cSpriteRenderer->SetSprite(false, app->GetRessourceManager()->GetAssetPath("heart_sprite"), sf::Color::White);
	cSpriteRenderer->SetSprite(false, app->GetRessourceManager()->GetAssetPath("heart_sprite"), sf::Color::White);
	player->setScale(sf::Vector2f(0.2f, 0.2f));

	KE::CScriptLua* scriptComp = app->AddComponent<KE::CScriptLua>(player);
	scriptComp->SetScript("lua_test");

	KE::CRigidbody* cRigidBody = app->AddComponent<KE::CRigidbody>(player);
	KE::CBoxCollider* cBox = app->AddComponent<KE::CBoxCollider>(player);

	cRigidBody->SetBodyType(b2BodyType::b2_dynamicBody);
	cRigidBody->SetGravityScale(0);
	cRigidBody->SetAngularDamping(10000);
	cBox->SetDensity(10.0f);	
	cBox->SetSize(1.5f, 1.5f);
	cBox->SetFixture(cRigidBody->GetBody());
	cRigidBody->SetLinearVelocity(b2Vec2(0, 0));

	//Sol Bottom
	KE::Entity* sol = app->CreateEntity();
	sol->SetName("Sol");
	sol->setPosition(0, 75);
	KE::CRigidbody* rbSol = app->AddComponent<KE::CRigidbody>(sol);
	KE::CBoxCollider* cBoxSol = app->AddComponent<KE::CBoxCollider>(sol);
	rbSol->SetBodyType(b2BodyType::b2_staticBody);	
	cBoxSol->SetDensity(100.0f);
	cBoxSol->SetSize(1000.f, 2.f);	
	cBoxSol->SetFixture(rbSol->GetBody());

	//Sol2 top
	KE::Entity* sol2 = app->CreateEntity();
	sol2->SetName("Sol2");
	sol2->setPosition(0, -125);
	KE::CRigidbody* rbSol2 = app->AddComponent<KE::CRigidbody>(sol2);
	KE::CBoxCollider* cBoxSol2 = app->AddComponent<KE::CBoxCollider>(sol2);
	rbSol2->SetBodyType(b2BodyType::b2_staticBody);
	cBoxSol2->SetDensity(100.0f);
	cBoxSol2->SetSize(1000.f, 2.f);
	cBoxSol2->SetFixture(rbSol2->GetBody());

	//Sol2 Right
	KE::Entity* sol3 = app->CreateEntity();
	sol3->SetName("Sol2");
	sol3->setPosition(175.f, 0);
	KE::CRigidbody* rbSol3 = app->AddComponent<KE::CRigidbody>(sol3);
	KE::CBoxCollider* cBoxSol3 = app->AddComponent<KE::CBoxCollider>(sol3);
	rbSol3->SetBodyType(b2BodyType::b2_staticBody);
	cBoxSol3->SetDensity(100.0f);
	cBoxSol3->SetSize(2.f, 1000.f);
	cBoxSol3->SetFixture(rbSol3->GetBody());

	//Sol2 Left
	KE::Entity* sol4 = app->CreateEntity();
	sol4->SetName("Sol2");
	sol4->setPosition(-175.f, 0);
	KE::CRigidbody* rbSol4 = app->AddComponent<KE::CRigidbody>(sol4);
	KE::CBoxCollider* cBoxSol4 = app->AddComponent<KE::CBoxCollider>(sol4);
	rbSol4->SetBodyType(b2BodyType::b2_staticBody);
	cBoxSol4->SetDensity(100.0f);
	cBoxSol4->SetSize(2.f, 1000.f);
	cBoxSol4->SetFixture(rbSol4->GetBody());
	
	KE::Entity* camera = app->CreateEntity();
	camera->SetName("MainCamera");
	KE::CCamera* cCamera = app->AddComponent<KE::CCamera>(camera);
	cCamera->SetView(sf::FloatRect(app->_window.getSize().x/2, app->_window.getSize().y / 2, 1250, 720));
	//cCamera->SetViewport(sf::FloatRect(0, 0, 0.7, 0.7));
	cCamera->SetZoom(app->_window.getSize().x/2, app->_window.getSize().y/2);	

	KE::Entity* enemySpawner = app->CreateEntity();
	EnemySpawner* spawnerComponent = app->AddComponent<EnemySpawner>(enemySpawner);
	
    app->Init();
	

    app->UpdateLoop();

    return 0;
}