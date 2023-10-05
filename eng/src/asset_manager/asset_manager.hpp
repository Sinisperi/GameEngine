#pragma once
#include "shader/shader.hpp"
#include <map>

namespace eng
{
    class AssetManager
    {
	public:
	    static Shader* GetShader(const char* name);
	    static void LoadShader(const char* vertPath, const char* fragPath, const char* name);

	private:
	    AssetManager() = delete;
	    static std::map<const char*, Shader*> m_Shaders;
    };
}
