#include "Window.h"

void Window::ClearScreen() {
	glClearColor(0,255,255,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw WindowException(SDL_GetError());
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
	
	InitWindow(windowTitle);
	InitContext();
	ClearScreen();
}

void Window::Update() {
	SDL_GL_SwapWindow(_windowScreen);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Window::~Window() {
	SDL_GL_DeleteContext(_glContext);
	SDL_DestroyWindow(_windowScreen);
	SDL_Quit();
}

void Window::InitContext() {
	//TODO: platformdetector

	_glContext = SDL_GL_CreateContext(_windowScreen);
	SDL_GL_MakeCurrent(_windowScreen, _glContext);
	glewExperimental = GL_TRUE;
	try
	{
		if (_glContext == nullptr || glewInit() != 0) {
			std::stringstream error;
			error << SDL_GetError() << "\t" <<glGetError();
			throw WindowException(error.str());
		}
		if (SDL_GL_SetSwapInterval(0) != 0) {
			std::stringstream error;
			error << "SetSwapInterval [Enable V-Sync]: " << SDL_GetError();
			throw WindowException(error.str());
		}
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
	}
	catch(WindowException& ex)
	{
		std::cout << ex.what() << std::endl;
	}


}
