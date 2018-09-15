#include "TestState2.h"

TestState2::TestState2() {
	//_applicationInstance = applicationInstance;
}

TestState2::~TestState2() {

}

bool TestState2::Init() {
	glClearColor(0, 0, 255, 1);
	return true;
}

bool TestState2::Destroy() {
	return true;
}

bool TestState2::Update(SDL_Keycode key) {
	glClear(GL_COLOR_BUFFER_BIT);
	return true;
}
