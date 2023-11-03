#include "CScriptLua.h"
#include "Application.h"

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
		.beginClass<KE::Entity>("Entity")
		//.addProperty("position", &KE::Entity::GetPosition, &KE::Entity::SetPosition)
		.addFunction("getPosition", &KE::Entity::GetPosition)
		.addFunction("setPosition", &KE::Entity::SetPosition)
		.addFunction("update", &KE::Entity::Update)
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
	luabridge::LuaRef update = luabridge::getGlobal(_luaState, "update");
	luabridge::LuaResult result = update(deltaTime);
}

void KE::CScriptLua::ReportErrors(lua_State* luaState, int status)
{
	if (status == 0) {
		return;
	}

	std::cerr << "[LUA ERROR] " << lua_tostring(luaState, -1) << std::endl;
	lua_pop(luaState, 1);
}
