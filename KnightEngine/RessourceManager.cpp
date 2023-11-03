#include "RessourceManager.h"

KE::RessourceManager::RessourceManager()
{	
	const std::string path = GetExePath() + "\\Resources.yaml";
	std::cout << path << std::endl;
	_base = YAML::LoadFile(path);
}

KE::RessourceManager::~RessourceManager()
{
	delete &_base;
}

std::string KE::RessourceManager::GetAssetPath(std::string id)
{
	if (_base["assets"]) {
		for (auto asset : _base["assets"]) {
			if (asset["id"].as<std::string>() == id) {				
				return  GetExePath() + "\\" + asset["path"].as<std::string>();
			}
		}
	}
	return std::string();
}

std::string KE::RessourceManager::GetExePath()
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, sizeof(buffer));
	_exePath = std::filesystem::path(buffer).parent_path().string();
	return _exePath;
}
