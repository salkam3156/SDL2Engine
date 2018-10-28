#include "MoveCommand.h"

void MoveCommand::Exectue(IEntity & entity)
{
	entity.Move();
}
