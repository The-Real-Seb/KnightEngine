#pragma once
#include <lua.hpp>
#include <luabridge3/LuaBridge/LuaBridge.h>
#include "AComponent.h"

namespace KE {
	class CScriptLua : public AComponent
	{
	protected:
		lua_State* _luaState;
		void ReportErrors(lua_State* luaState, int status);

	public:
		CScriptLua();
		void SetScript(std::string assetID);
		void Update(float deltaTime);
		void Awake();

		void BeginCollision();
		void EndCollision();
	};
}


