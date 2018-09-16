#pragma once
#include "StandardHeader.h"
#include "Window.h"
#include "Interfaces/IGameState.h"
#include "Types/Shape.h"

class InstanceException: public std::runtime_error {
public:
	InstanceException(const std::string& errorMsg) :
			std::runtime_error(errorMsg) {
	}
};

class Instance {
private:
	Instance();
	Instance(const Instance&) = delete;
	~Instance();

	static Instance* _applicationInstance;

public:
	static Instance* GetInstance();
	bool Running() const;
	void Update();
	void Stop();
	//TODO: move back to private after debugging and creating states
	void UpdateWindow();

	template<typename T>
	void SetState();

private:
	bool _running;
	Window* _window;
	IGameState* _gameState;
};
