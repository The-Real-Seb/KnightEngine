#include "CScriptLua.h"
#include "Application.h"
#include "CCollider.h"
#include "CBoxCollider.h"
#include "CRigidbody.h"
#include "CSpriteRenderer.h"

KE::CScriptLua::CScriptLua()
{
	_luaState = luaL_newstate();
	luaL_openlibs(_luaState);

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass<sf::Vector2f>("Vector2")		
		.addProperty("x", &sf::Vector2f::x)
		.addProperty("y", &sf::Vector2f::y)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass<b2Vec2>("B2Vec")
		.addConstructor<void (*) (void)>()
		.addProperty("x", &b2Vec2::x)
		.addProperty("y", &b2Vec2::y)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass<KE::Entity>("Entity")
		.addFunction("Awake", &KE::Entity::Awake)
		//.addProperty("position", &KE::Entity::GetPosition, &KE::Entity::SetPosition)
		.addFunction("GetPosition", &KE::Entity::GetPosition)
		.addFunction("SetPosition", &KE::Entity::SetPosition)
		.addFunction("Update", &KE::Entity::Update)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass<KE::Application>("Application")
		.addStaticFunction("GetInstance", &KE::Application::GetInstance)
		.addFunction("GetEntity", &KE::Application::GetEntity)
		.addFunction("GetEntityByName",  &KE::Application::GetEntityByName)
		.addProperty("Keyboard", &KE::Application::luaKeyboard)
		.addFunction("GetRigiBodyComponent", &KE::Application::GetRigiBodyComponent)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass<KE::RessourceManager>("RessourceManager")
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <KE::CCollider> ("Collider")
		//.addFunction("BeginCollision", &KE::CBoxCollider::BeginCollision)
		//.addFunction("EndCollision", &KE::CBoxCollider::EndCollision)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <KE::Collision>("Collision")		
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <KE::CBoxCollider>("BoxCollider")
		//.addFunction("BeginCollision", &KE::CBoxCollider::BeginCollision)
		//.addFunction("EndCollision", &KE::CBoxCollider::EndCollision)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <KE::CRigidbody>("RigidBody")
		.addFunction("SetVelocity", &KE::CRigidbody::SetLinearVelocity)
		.addFunction("AddImpulse", &KE::CRigidbody::ApplyImpulseToCenter)
		.addFunction("AddForce", &KE::CRigidbody::ApplyForceToCenter)
		.addFunction("SetLinearDamp", &KE::CRigidbody::SetLinearDamping)
		.endClass()
		.endNamespace();

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <KE::CSpriteRenderer>("SpriteRender")
		.addFunction("SetTexture", &KE::CSpriteRenderer::SetTexture)
		.endClass()
		.endNamespace();	

	luabridge::getGlobalNamespace(_luaState)
		.beginNamespace("KnightEngine")
		.beginClass <LuaKeyboard>("Keyboard")
		.addFunction("isKeyPressed", &KE::LuaKeyboard::isKeyPressed)
		.endClass()
		.endNamespace();	
}

void KE::CScriptLua::SetScript(std::string assetID)
{
	std::string path = KE::Application::GetInstance()->GetRessourceManager()->GetAssetPath(assetID);

	int scriptLoadStatus = luaL_dofile(_luaState, path.c_str());

	ReportErrors(_luaState, scriptLoadStatus);
}

void KE::CScriptLua::Update(float deltaTime)
{
	luabridge::LuaRef update = luabridge::getGlobal(_luaState, "Update");
	luabridge::LuaResult result = update(deltaTime);
}

void KE::CScriptLua::Awake()
{
	luabridge::LuaRef awake = luabridge::getGlobal(_luaState, "Awake");
	luabridge::LuaResult result = awake();
}

void KE::CScriptLua::BeginCollision()
{
	luabridge::LuaRef beginCollision = luabridge::getGlobal(_luaState, "beginCollision");
	luabridge::LuaResult result = beginCollision();
}

void KE::CScriptLua::EndCollision()
{
	luabridge::LuaRef endCollision = luabridge::getGlobal(_luaState, "endCollision");
	luabridge::LuaResult result = endCollision();
}

void KE::CScriptLua::ReportErrors(lua_State* luaState, int status)
{
	if (status == 0) {
		return;
	}

	std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;
	lua_pop(luaState, 1);
}
