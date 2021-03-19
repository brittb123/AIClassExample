#include "EvadingBehaviour.h"
#include "Agent.h"
#include "Actor.h"

EvadingBehaviour::EvadingBehaviour()
{
	m_target = nullptr;
	setForce(1);
}

EvadingBehaviour::EvadingBehaviour(Actor* target, float seekForce)
{
	m_target = target;
	setForce(1);
}

MathLibrary::Vector2 EvadingBehaviour::calculateForce(Agent* agent)
{
	
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize((m_target->getWorldPosition() + m_target->getVelocity()) - agent->getWorldPosition());
	
	MathLibrary::Vector2 desiredVelocity = direction * getForce();
	
	MathLibrary::Vector2 steeringForce = desiredVelocity + agent->getVelocity();

	return steeringForce;
}

void EvadingBehaviour::update(Agent* agent, float deltaTime)
{
	if (agent)
		agent->addForce(calculateForce(agent));
}