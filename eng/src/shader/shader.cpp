#include "shader.hpp"
#include <glad/glad.h>
#include <iostream>

namespace eng
{
    Shader::Shader(const char* vertSource, const char* fragSource)
    {
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertSource, nullptr);
	glCompileShader(vertexShader);
	CheckCompileStatus(vertexShader, "VERTEX");

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSource, nullptr);
	glCompileShader(fragmentShader);
	CheckCompileStatus(fragmentShader, "FRAGMENT");

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertexShader);
	glAttachShader(m_ID, fragmentShader);
	CheckLinkStatus(m_ID);
    }

    void Shader::Use()
    {
	glUseProgram(m_ID);
    }


    void Shader::CheckCompileStatus(unsigned int shader, const char* name)
    {
	int success;
	char infoLog[1024];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
	    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
	    std::cout << name << std::endl;
	    std::cout << infoLog << std::endl;
	    std::cout << "====================" << std::endl;
	}

    }

    void Shader::CheckLinkStatus(unsigned int program)
    {
	int success;
	char infoLog[1024];

	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if(!success)
	{
	    glGetProgramInfoLog(program, 1024, NULL, infoLog);
	    std::cout << "PROGRAM" << std::endl;
	    std::cout << infoLog << std::endl;
	    std::cout << "====================" << std::endl;
	}

    }
}
