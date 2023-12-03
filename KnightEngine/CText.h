#pragma once
#include "AComponent.h"

namespace KE {
	class CText : public AComponent, public sf::Drawable
	{
	private:
		sf::Text _text;
		sf::Font _font;
	public:

		void SetString(std::string text);
		void SetFont(std::string path);
		void SetSize(int pixel);
		void SetFillColor(sf::Color color);
		void SetStyle(sf::Text::Style style);
		std::string SetFloatPrecision(float i);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	};
}


