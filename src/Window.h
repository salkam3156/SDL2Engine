#pragma once

#include "StandardHeader.h"

class WindowException : public std::runtime_error
{
public:
	WindowException(std::string errorMsg) : std::runtime_error(errorMsg)
	{
	}
};

class Window
{
public:

	Window(const std::string& windowTitle);
	Window(const Window&) = delete;
	~Window();
	void Update();
private:
	SDL_Window* _windowScreen;
	SDL_GLContext _glContext;
	void InitContext();
	void InitWindow(const std::string& windowTitle);
	void ClearScreen();
};
