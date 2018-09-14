#include "StandardHeader.h"
#include "Types/TestState.h"
#include "Instance.h"


int main(int argc, char* args[])
{
	int retVal = 0;
	auto instance = Instance::GetInstance();

	while(instance->Running())
	{
		instance->Run();
	}
//	SDLSetup setup;
//	setup.InitializeSdl();
//
//	SDL_Window* window = nullptr;
//	SDL_Renderer* displayRenderer = nullptr;
//	SDL_RendererInfo* rendererInfo = nullptr;
//
//	SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN, &window, &displayRenderer);//("MainWindow", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
//	SDL_GetRendererInfo(displayRenderer, rendererInfo);
//
//	auto context = SDL_GL_CreateContext(window);
//	auto error = SDL_GetError();
//
//	if(!context)
//	{
//		return -1;
//	}
//
//	glewExperimental = GL_TRUE;
//	auto glewError = glewInit();
//	setup.InitializeGl();
//
//	if(glewError != GLEW_OK)
//	{
//		return -2;
//	}
//
//	if(!GLEW_VERSION_3_3)
//	{
//		printf("derp");
//	}
//
//
//	SDL_DestroyWindow(window);

	return retVal;
}
