#pragma once
#include "../StandardHeader.h"

struct SDLDestructor {
	void operator()(SDL_Window* ptr) const {
		SDL_DestroyWindow(ptr);
	}
	void operator()(SDL_Renderer *ptr) const {
		SDL_DestroyRenderer(ptr);
	}
	void operator()(SDL_Texture *ptr) const {
		SDL_DestroyTexture(ptr);
	}
};
