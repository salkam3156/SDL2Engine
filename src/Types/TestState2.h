#pragma once
#include "../StandardHeader.h"
#include "../Instance.h"
#include "../Interfaces/IGameState.h"
#include "TestState.h"

class TestState2: public IGameState {
public:
	TestState2();
	~TestState2();
	bool Init() override;
	bool Update(SDL_Keycode key) override;
	bool Destroy() override;
private:
	Instance* _applicationInstance = nullptr;
};
