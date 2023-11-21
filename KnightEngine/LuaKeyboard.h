#pragma once
#include <iostream>
#include "SFML/Window/Event.hpp"
#include <map>

namespace KE {
	class LuaKeyboard
	{
	protected:
		std::map<std::string_view, bool> _events;
	public:
		void AddEvent(sf::Event event);
		bool isKeyPressed(std::string);

		void Clear();
	};
}


