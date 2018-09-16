#include "Window.h"

void Window::ClearScreen() {
	glClearColor(0,255,255,1);
}

void Window::InitWindow(const std::string& windowTitle) {
	_windowScreen = SDL_CreateWindow(windowTitle.c_str(),
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_ShowCursor(SDL_DISABLE);

	if (_windowScreen == nullptr) {
		throw WindowException(SDL_GetError());
	}
}

Window::Window(const std::string& windowTitle) :
		_windowScreen(nullptr), _glContext(nullptr) {
	InitWindow(windowTitle);
	InitContext();
}

void Window::Update() {
	ClearScreen();
	SDL_GL_SwapWindow(_windowScreen);
}

Window::~Window() {
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(_windowScreen);
}

void Window::InitContext() {
	//TODO: initialize glew here after context creation and handle accordingly , should it fail
	//TODO: platformdetector
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	_glContext = SDL_GL_CreateContext(_windowScreen);
	auto glewInitialized = glewInit();
	if (_glContext == nullptr || glewInitialized != 0) {
		std::stringstream error;
		error << SDL_GetError() << glGetError();
		throw WindowException(error.str());
	}
	try {
		if (SDL_GL_SetSwapInterval(1) < 0) {
			throw WindowException(SDL_GetError());
		}
	} catch (WindowException& exception) {
		std::cout << "SetSwapInterval [Enable V-Sync]: " << SDL_GetError()
				<< std::endl;
	}
}
