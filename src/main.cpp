#include "StandardHeader.h"
#include "Types/TestState.h"
#include "Instance.h"
#include "Shaders/ShaderProgram.h"
#include "Types/Shape.h"
#include "Types/Camera.h"
#include "../res/Quad.h"

//TODO: create overall logging and exception classes , and do logging on exception ctor invocation
//TODO: wrap stuff into unique ptrs
//TODO: resource factory
//TODO: platform checker, and dynamically assigning shader versions (modify #version ?) in the shader files / shader generator
//TODO: model loader
//TODO: input handler

int main(int argc, char* args[]) {
	int retVal = 0;

	auto instance = Instance::GetInstance();
	ShaderProgram shaderProgram = ShaderProgram("res/vertex.shader", "res/fragment.shader");
	shaderProgram.Use();
	Shape shape(&shaderProgram);
	Camera camera(&shaderProgram);
	camera.SetTranslation(0, 0, -2);

	while (instance->Running()) {
		SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					instance->Stop();
					break;
				case SDL_KEYDOWN:
					camera.Translate(0,0,-0.5);

					break;
				default:
					break;
				}
			}
			glClear(GL_COLOR_BUFFER_BIT);
			shape.Draw();
			camera.Update();
			instance->UpdateWindow();

	}

	return retVal;
}
