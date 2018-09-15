#pragma once
#include "../StandardHeader.h"

class IGameState {
public:
	virtual bool Init() = 0;
	virtual bool Update(SDL_Keycode key) = 0;
	virtual bool Destroy() = 0;
	virtual ~IGameState() {
	}
};

template<class T>
IGameState* CreateClass() {
	return new T();
}
