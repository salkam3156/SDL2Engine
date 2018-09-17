#include "StandardHeader.h"
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
//TODO: tweening for input

int main(int argc, char* args[]) {
	int retVal = 0;
	int framerate = 60;
	int frameTime = 1000 /60;

	auto instance = Instance::GetInstance();
	ShaderProgram shaderProgram = ShaderProgram("res/vertex.shader", "res/fragment.shader");
	shaderProgram.Use();
	Shape shape(&shaderProgram);
	Camera camera(&shaderProgram);
	camera.SetTranslation(0, 0, -5);
	camera.SetRotation(0, 0, 0, -5);
	camera.Update();
	auto lastFrameTime = SDL_GetTicks();

	while (instance->Running()) {

		SDL_Event event;
			while (SDL_PollEvent(&event)) {

				if(event.type == SDL_QUIT)
				{
					instance->Stop();
				}
				if(event.type == SDL_KEYDOWN)
				{
					if(event.key.keysym.sym == SDLK_UP)
					{
						camera.Translate(0, 0, 0.5);
					}else if(event.key.keysym.sym == SDLK_DOWN)
					{
						camera.Translate(0, 0, -0.5);
					}
					else if(event.key.keysym.sym == SDLK_LEFT)
					{
						camera.Rotate(-1.5,0, 1, 0);
					}
					else if(event.key.keysym.sym == SDLK_RIGHT)
					{
						camera.Rotate(1.5,0, 1, 0);
					}
				}
			}
			camera.Update();
			if(SDL_GetTicks() - lastFrameTime > frameTime)
			{
				glClear(GL_COLOR_BUFFER_BIT);
				shape.Draw();
				instance->UpdateWindow();
				lastFrameTime = SDL_GetTicks();
			}

	}

	return retVal;
}
