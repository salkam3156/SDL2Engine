#pragma once
#include "../StandardHeader.h"
#include "../Interfaces/ICommand.h"

class InputHanlder
{
public:
	ICommand::Ptr Handle();

private:
	ICommand::Ptr buttonLeft;
	ICommand::Ptr buttonRight;
	ICommand::Ptr buttonUp;
	ICommand::Ptr buttonDown;

};