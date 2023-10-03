#pragma once
#include "window/window.hpp"

namespace eng
{
    class Game {

	public:
	    Game(const char* name = "Unitiled Game", unsigned int width = 854, unsigned int height = 480);
	    virtual ~Game();

	public:
	    void Run();

	private:
	    bool m_Running;
	    Window* m_Window;

	private:
	    void EventListener(Event& e);
    };
}
