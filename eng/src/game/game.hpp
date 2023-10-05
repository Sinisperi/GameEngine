#pragma once
#include "window/window.hpp"
#include "render_api/render_api.hpp"

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
	    RenderAPI* m_RenderAPI;

	private:
	    void EventListener(Event& e);
    };
}
