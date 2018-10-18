#pragma once
#include "../StandardHeader.h"
#include "IEntity.h"

class ICommand
{
public:
	using Ptr = std::unique_ptr<ICommand>;

public:
	virtual void Exectue(IEntity& entity) = 0;
};