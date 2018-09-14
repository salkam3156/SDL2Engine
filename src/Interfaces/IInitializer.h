#pragma once

enum class ReturnCode
{
	SUCCESS,
	FAILURE
};

class IInitializer
{
public:
	virtual ReturnCode Initialize() = 0;
	virtual ~IInitializer();
};
