#include "DecisionBehaviour.h"
#include "Decision.h"


void DecisionBehaviour::update(Agent* agent, float deltatime)
{
	if (agent)
		m_root->makeDecision(agent, deltatime);
}
