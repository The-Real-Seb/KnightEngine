#include "LuaKeyboard.h"
#include "SFML/Window/Event.hpp"
#include "magic_enum.hpp"


void KE::LuaKeyboard::AddEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {

        std::string_view string = magic_enum::enum_name(event.key.code);       
        
        _events[string] = true;
    }

    if (event.type == sf::Event::KeyReleased) {

        std::string_view string = magic_enum::enum_name(event.key.code);        

        if (_events.contains(string)) {
            _events.erase(string);
        }
    }
}

bool KE::LuaKeyboard::isKeyPressed(std::string keyString)
{
    if (_events.contains(keyString)) {
        return true;
    }     
    return false;
}

void KE::LuaKeyboard::Clear()
{
    
   //_events.clear();
}
