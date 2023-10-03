#pragma once
#include <GLFW/glfw3.h>
#include <functional>

namespace eng 
{
    using WindowEventListener = std::function<void(/*Event*/)>;
    class Window
    {
	public:
	    Window(unsigned int width, unsigned int height, const char* title);
	    void SetWindowEventListener(const WindowEventListener& el);
	    void Update();


	private:
	    struct WindowData
	    {
		unsigned int width, height;
		const char* title;
		WindowEventListener EventListener;
		WindowData(unsigned int w, unsigned int h, const char* t)
		    : width(w), height(h), title(t) {};

	    };

	    WindowData m_WindowData;
	    GLFWwindow* m_WindowHandle;
    };
}
