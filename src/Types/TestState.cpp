#include "TestState.h"

TestState::TestState() {
	//_applicationInstance = applicationInstance;
}

TestState::~TestState() {

}

bool TestState::Init() {
	glClearColor(0, 255, 255, 1);
	return true;
}

bool TestState::Destroy() {
	return true;
}

bool TestState::Update(SDL_Keycode key) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	auto state = SDL_GetKeyboardState(nullptr);
//	if(state[SDL_SCANCODE_LEFT])
//	{
//		_applicationInstance->SetState<TestState2>(_applicationInstance);
//	}
	return true;
}
