#pragma once
#include "../StandardHeader.h"

class IEntity
{
public:
	virtual void Move() = 0;
	virtual void Turn() = 0;
	~IEntity() {}
};