#include "CText.h"
#include <iostream>

void KE::CText::SetString(std::string text)
{
	_text.setString(text);
}

void KE::CText::SetFont(std::string path)
{
	
	if (!_font.loadFromFile(path))
	{
		std::cout << "Can't load font" << std::endl;
	}

	_text.setFont(_font);
}

void KE::CText::SetSize(int pixel)
{
	_text.setCharacterSize(pixel);

	float size = (_text.getCharacterSize()/2);
	_text.setPosition(-size, -size);
}

void KE::CText::SetFillColor(sf::Color color)
{
	_text.setFillColor(color);
}

void KE::CText::SetStyle(sf::Text::Style style)
{
	_text.setStyle(style);
}

void KE::CText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{	
	target.draw(_text, states);	
}
