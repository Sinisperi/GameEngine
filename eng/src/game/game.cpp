#include "game.hpp"
#include <glad/glad.h>
#include <iostream>

namespace eng
{
    Game::Game(const char* name, unsigned int width, unsigned int height)
	: m_Running(true)
    {
	m_Window = new Window(width, height, name);

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
	    m_Window->Update();
	}
    }
}
