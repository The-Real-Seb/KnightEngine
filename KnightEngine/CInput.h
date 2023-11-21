#pragma once
#include "AComponent.h"
#include "SFML/System/InputStream.hpp"

namespace KE {
	class CInput : public AComponent
	{
	public:
		CInput();
		~CInput();

		std::string OnInput();
	};
}


