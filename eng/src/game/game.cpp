#include "game.hpp"
#include "GLFW/glfw3.h"
#include <glad/glad.h>
#include <iostream>

namespace eng
{
    void glfwErrorCallback(int errCode, const char* msg)
    {
	std::cout << "[GLFW ERROR]: " << errCode << std::endl;
	std::cout << msg << std::endl;

    }
    Game::Game(const char* name, unsigned int width, unsigned int height)
	: m_Running(true)
    {
	glfwSetErrorCallback(glfwErrorCallback);
	glfwInit();
	m_Window = glfwCreateWindow(width, height, name, nullptr , nullptr);
	glfwMakeContextCurrent(m_Window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    }

    Game::~Game()
    {
    }

    void Game::Run()
    {
	while(m_Running)
	{
	    glClear(GL_COLOR_BUFFER_BIT);
	    glClearColor(0.4f, 0.3f, 0.5f, 1.0f);
	    glfwSwapBuffers(m_Window);
	    glfwPollEvents();
	}
    }
}
