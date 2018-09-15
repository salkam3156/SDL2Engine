#pragma once
#include "../StandardHeader.h"
#include "../Instance.h"
#include "../Interfaces/IGameState.h"
#include "TestState2.h"
#include "Shape.h"

class TestState: public IGameState {
public:
	TestState();
	~TestState();
	bool Init() override;
	bool Update(SDL_Keycode key) override;
	bool Destroy() override;

private:
	Instance* _applicationInstance = nullptr;
};
