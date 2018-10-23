#pragma once
#include "../StandardHeader.h"
#include "../Interfaces/ICommand.h"

class MoveCommand : public ICommand
{
	// Inherited via ICommand
	virtual void Exectue(IEntity & entity) override;
};