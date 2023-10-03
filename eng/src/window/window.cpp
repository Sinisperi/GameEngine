#include "window.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace eng
{
    void glfwErrorCallback(int errCode, const char* msg)
    {
	std::cout << "[GLFW ERROR]: " << errCode << std::endl;
	std::cout << msg << std::endl;

    }

    Window::Window(unsigned int width, unsigned int height, const char* title)
	: m_WindowData(width, height, title)
    {
	glfwSetErrorCallback(glfwErrorCallback);
	glfwInit();
	m_WindowHandle = glfwCreateWindow(width, height, title, nullptr , nullptr);
	glfwMakeContextCurrent(m_WindowHandle);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


    }

    void Window::SetWindowEventListener(const WindowEventListener& el)
    {
	m_WindowData.EventListener = el;
	
    }
    void Window::Update()
    {
	glfwSwapBuffers(m_WindowHandle);
	glfwPollEvents();
    }
}
