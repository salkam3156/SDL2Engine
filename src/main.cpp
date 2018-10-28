#include "StandardHeader.h"
#include "Instance.h"
#include "Shaders/ShaderProgram.h"
#include "Types/Shape.h"
#include "Types/Camera.h"
#include "../res/Quad.h"
#include "Utils/InputHandler.h"

//TODO: create overall logging and exception classes , and do logging on exception ctor invocation
//TODO: wrap stuff into unique ptrs
//TODO: resource factory
//TODO: platform checker, and dynamically assigning shader versions (modify #version ?) in the shader files / shader generator
//TODO: model loader
//TODO: tweening for input
int main(int argc, char* args[]) {
	int mouseX = 0;
	int mouseY = 0;
	int retVal = 0;
	int framerate = 60;
	int frameTime = 1000 /60;
	auto instance = Instance::GetInstance();
	auto shaderProgram = ShaderProgram::MakeShaderProgram("res/lighting.vert", "res/lighting.frag");
	shaderProgram->Use();
	Shape shape(shaderProgram);
	Camera camera(shaderProgram);
	
	auto lastFrameTime = SDL_GetTicks();
	shaderProgram->SetUniformVec4("uniColor", { 1.0, 1.0, 1.0, .0 });
	InputHanlder inputHandler = {};


	while (instance->Running()) {

		SDL_Event event;
			while (SDL_PollEvent(&event)) {

				if(event.type == SDL_QUIT)
				{
					instance->Stop();
				}
				if (event.type == SDL_WINDOWEVENT)
				{
					if (event.window.event == SDL_WINDOWEVENT_RESIZED)
					{
						glViewport(0, 0, event.window.data1, event.window.data2);
					}
				}
			}

			if(SDL_GetTicks() - lastFrameTime > frameTime)
			{
				if (auto command = inputHandler.Handle())
				{
					command->Exectue(camera);
				}
				SDL_GetMouseState(&mouseX, &mouseY);
				shaderProgram->SetUniformVec2("light_source", {mouseX/(float)640, mouseY/ (float)480});
				camera.Update();
				
				shape.Draw();
				instance->UpdateWindow();
				lastFrameTime = SDL_GetTicks();
			}
	}

	return retVal;
}