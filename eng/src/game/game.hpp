#pragma once
#include <GLFW/glfw3.h>

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
	    GLFWwindow* m_Window;
    };
}
