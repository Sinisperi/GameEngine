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
	m_RenderAPI = new RenderAPI(m_Window->getProc());
    }

    Game::~Game()
    {
	delete m_RenderAPI;
	delete m_Window;
    }

    void Game::Run()
    {
	while(m_Running)
	{
	    m_RenderAPI->Update();
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
