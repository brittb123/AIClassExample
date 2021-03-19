#include "PursueBehaviour.h"
#include "Agent.h"
#include "Actor.h"


PursueBehaviour::PursueBehaviour()
{
	m_target = nullptr;
	setForce(1);
}

PursueBehaviour::PursueBehaviour(Actor* target, float pursueForce = 1)
{
	m_target = target;
	setForce(pursueForce);
}

MathLibrary::Vector2 PursueBehaviour::calculateForce(Agent* agent)
{
	
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize((m_target->getWorldPosition() + m_target->getVelocity()) - agent->getWorldPosition());

	MathLibrary::Vector2 desiredVel = direction * getForce();

	MathLibrary::Vector2 steeringForce = desiredVel - agent->getVelocity();

	return steeringForce;
}

void PursueBehaviour::update(Agent* agent, float deltaTime)
{
	if (agent)
		agent->addForce(calculateForce(agent));
}