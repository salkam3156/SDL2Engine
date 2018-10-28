#include "InputHandler.h"
#include "../Actions/MoveCommand.h"

ICommand::Ptr InputHanlder::Handle()
{
	auto keyState = SDL_GetKeyboardState(nullptr);

	if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_RIGHT])
	{
		return std::make_unique<MoveCommand>();
	}
	else if (keyState[SDL_SCANCODE_Q] || keyState[SDL_SCANCODE_W])
	{
		//TODO: turn command
	}

	return {};
}
