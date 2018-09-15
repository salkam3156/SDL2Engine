#pragma once

#include "StandardHeader.h"

//TODO: extract into a base class for all of the exceptions

class WindowException: public std::runtime_error {
public:
	WindowException(std::string errorMsg) :
			std::runtime_error(errorMsg) {
	}
};

class Window {
	using WindowPtr = std::unique_ptr<SDL_Window*, decltype(&SDL_DestroyWindow)>;
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
