#include "game.hpp"
#include <functional>
#include <glad/glad.h>
#include "event/event.hpp"
#include <iostream>

namespace eng
{
    Game::Game(const char* name, unsigned int width, unsigned int height)
	: m_Running(true)
    {
	m_Window = new Window(width, height, name);
	m_Window->SetWindowEventListener(std::bind(&Game::EventListener, this, std::placeholders::_1));

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

    void Game::EventListener(Event& e)
    {
	EventDispatcher d(e);
	d.dispatch<WindowClosed>([this](Event& e){
	    m_Running = false;
	    return true;
	});

    }
}
