//#include <SFML/Graphics.hpp>
#include <KnightEngine/AComponent.h>
#include <KnightEngine/Entity.h>
#include <KnightEngine/CCircleShape.h>
#include <KnightEngine/CSpriteRenderer.h>
#include <KnightEngine/CCamera.h>
#include <KnightEngine/CGravity.h>
#include <KnightEngine/CRigidbody.h>
#include <KnightEngine/CBoxCollider.h>
#include <KnightEngine/CCollider.h>
#include <KnightEngine/Application.h>
#include <KnightEngine/CScriptLua.h>

int main()
{
	KE::Application* app = new KE::Application();
    app->Open();

	KE::Entity* entity1 = app->CreateEntity();
	entity1->SetName("Entite 1");
	entity1->setPosition(0, -100);

	KE::CSpriteRenderer* cSpriteRenderer = app->AddComponent<KE::CSpriteRenderer>(entity1);
	cSpriteRenderer->SetSprite(false, app->GetRessourceManager()->GetAssetPath("heart_sprite"), sf::Color::White);	

	KE::CScriptLua* scriptComp = app->AddComponent<KE::CScriptLua>(entity1);
	scriptComp->SetScript("lua_test");

	KE::CRigidbody* cRigidBody = app->AddComponent<KE::CRigidbody>(entity1);
	KE::CBoxCollider* cBox = app->AddComponent<KE::CBoxCollider>(entity1);

	cRigidBody->SetBodyType(b2BodyType::b2_dynamicBody);	
	//cRigidBody->SetLinearVelocity(b2Vec2(0,0));
	cBox->SetDensity(50.0f);
	cBox->SetSize(1.f, 1.f);
	cBox->SetFixture(cRigidBody->GetBody());

	KE::Entity* sol = app->CreateEntity();
	sol->SetName("Sol");
	sol->setPosition(0, 400);	

	KE::CRigidbody* rbSol = app->AddComponent<KE::CRigidbody>(sol);
	KE::CBoxCollider* cBoxSol = app->AddComponent<KE::CBoxCollider>(sol);

	rbSol->SetBodyType(b2BodyType::b2_staticBody);
	//cRigidBody->SetLinearVelocity(b2Vec2(0,0));
	cBoxSol->SetDensity(100.0f);
	cBoxSol->SetSize(100.f, 5.f);
	cBoxSol->SetFixture(rbSol->GetBody());
	
	KE::Entity* camera = app->CreateEntity();
	camera->SetName("MainCamera");
	KE::CCamera* cCamera = app->AddComponent<KE::CCamera>(camera);
	cCamera->SetView(sf::FloatRect(app->_window.getSize().x/2, app->_window.getSize().y / 2, 1250, 720));
	//cCamera->SetViewport(sf::FloatRect(0, 0, 0.7, 0.7));
	cCamera->SetZoom(app->_window.getSize().x, app->_window.getSize().y);
	
    app->Init();
	

    app->UpdateLoop();

    return 0;
}