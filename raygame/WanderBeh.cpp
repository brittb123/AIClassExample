#include "WanderBeh.h"
#include "ComplexEnemy.h"

void WanderBeh::makeDecision(Agent* agent, float deltatime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (enemy)
	{
		enemy->getSeek()->setEnabled(false);
		enemy->getWander()->setEnabled(true);
		enemy->getFlee()->setEnabled(false);
	}
}
