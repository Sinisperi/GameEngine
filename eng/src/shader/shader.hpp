#pragma once

namespace eng
{
    class Shader
    {
	public:
	    unsigned int m_ID;
	public:
	    Shader(const char* vertSource, const char* fragSource);
	    void Use();
	private:
	    void CheckCompileStatus(unsigned int shader, const char* name);
	    void CheckLinkStatus(unsigned int program);
    };
}
