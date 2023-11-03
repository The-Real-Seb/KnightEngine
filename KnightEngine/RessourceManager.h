#pragma once
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <windows.h>

namespace KE {
	class RessourceManager
	{
	private:
		YAML::Node _base;
		std::string _exePath;

	public:
		RessourceManager();
		~RessourceManager();

		std::string GetAssetPath(std::string id);
		std::string GetExePath();
	};
}


