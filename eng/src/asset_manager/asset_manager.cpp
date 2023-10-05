#include "asset_manager.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

namespace eng
{
    std::map<const char*, Shader*> AssetManager::m_Shaders;
    Shader* AssetManager::GetShader(const char* name)
    {
	return m_Shaders[name];
    }

    void AssetManager::LoadShader(const char* vertPath, const char* fragPath, const char* name)
    {
	std::string vertString, fragString;

	try
	{
	    std::stringstream vertStream, fragStream;
	    std::fstream vertFile(vertPath);
	    std::fstream fragFile(fragPath);
	    vertStream << vertFile.rdbuf();
	    fragStream << fragFile.rdbuf();
	    vertString = vertStream.str();
	    fragString = fragStream.str();

	} catch(std::exception& e)
	{
	    std::cout << "Wasn't able to find/open/do/etc. " << std::endl;
	    std::cout << e.what() << std::endl;
	}

	const char* vertSource = vertString.c_str();
	const char* fragSource = fragString.c_str();
	Shader* s = new Shader(vertSource, fragSource);
	m_Shaders[name] = s;
    }
}
