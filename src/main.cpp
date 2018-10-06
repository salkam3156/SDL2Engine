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

void HandleInput(Camera& camera, int* mouseX, int* mouseY);

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
	camera.SetTranslation(0, 0, -5);
	camera.SetRotation(0, 0, 0, -5);
	//camera.Update();
	auto lastFrameTime = SDL_GetTicks();
	shaderProgram->SetUniformVec4("uniColor", { 1.0, 1.0, 1.0, .0 });


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
				HandleInput(camera, &mouseX, &mouseY);
				shaderProgram->SetUniformVec2("light_source", {mouseX/(float)640, mouseY/ (float)480});
				camera.Update();
				glClear(GL_COLOR_BUFFER_BIT);
				shape.Draw();
				instance->UpdateWindow();
				lastFrameTime = SDL_GetTicks();
				std::stringstream mousePos;
				mousePos << "Mouse x: " << mouseX << "\t" << "Mouse y: " << mouseY;
				//std::cout << glGetString(GLU_ERROR) << std::endl;
			}
	}

	return retVal;
}

void HandleInput(Camera& camera, int* mouseX, int* mouseY)
{
	auto keyState = SDL_GetKeyboardState(nullptr);
	SDL_GetMouseState(mouseX, mouseY);

	if(keyState[SDL_SCANCODE_UP])
	{
		camera.Translate(0, 0, 0.5);
	}
	else if(keyState[SDL_SCANCODE_DOWN])
	{
		camera.Translate(0, 0, -0.5);
	}
	else if(keyState[SDL_SCANCODE_LEFT])
	{
		camera.Rotate(-1.5,0, 1, 0);
	}
	else if(keyState[SDL_SCANCODE_RIGHT])
	{
		camera.Rotate(1.5,0, 1, 0);
	}

}
