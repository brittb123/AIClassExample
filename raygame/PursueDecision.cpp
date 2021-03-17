
#include "PursueDecision.h"
#include "ComplexEnemy.h"

void PursueDecision::makeDecision(Agent* agent, float deltatime)
{
	ComplexEnemy* enemy = dynamic_cast<ComplexEnemy*>(agent);

	if (enemy)
	{
		enemy->getSeek()->setEnabled(true);
		enemy->getWander()->setEnabled(false);
		enemy->getFlee()->setEnabled(false);
	}
}
