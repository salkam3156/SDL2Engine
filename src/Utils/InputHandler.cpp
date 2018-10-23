#include "InputHandler.h"

ICommand::Ptr InputHanlder::Handle()
{
	
	auto keyState = SDL_GetKeyboardState(nullptr);

	if (keyState[SDL_SCANCODE_UP])
	{

	}
	else if (keyState[SDL_SCANCODE_DOWN])
	{
	}
	else if (keyState[SDL_SCANCODE_Q])
	{
	}
	else if (keyState[SDL_SCANCODE_W])
	{
	}
	else if (keyState[SDL_SCANCODE_LEFT])
	{
	}
	else if (keyState[SDL_SCANCODE_RIGHT])
	{
	}

	
}
