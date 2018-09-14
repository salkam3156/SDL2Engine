#pragma once
#include "StandardHeader.h"
#include "Interfaces/IInitializer.h"

class SDLSetup
{
public:
	bool InitializeSdl();
	bool InitializeGl();
	~SDLSetup();
};
