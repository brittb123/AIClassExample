#include "evadeBehaviour.h"
#include "ComplexEnemy.h"

void evadeBehaviour::makeDecision(Agent* agent, float deltatime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (enemy)
	{
		enemy->getSeek()->setEnabled(false);
		enemy->getWander()->setEnabled(false);
		enemy->getFlee()->setEnabled(true);
	}
}
