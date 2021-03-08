#include "FleeBehaviour.h"
#include "Agent.h"
#include "Actor.h"

FleeBehaviour::FleeBehaviour()
{
	m_target = nullptr;
	setForce(1);
}

FleeBehaviour::FleeBehaviour(Actor* Target, float fleeforce)
{
	m_target = Target;
	setForce(fleeforce);
}

MathLibrary::Vector2 FleeBehaviour::calculateForce(Agent* agent)
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(agent->getWorldPosition() - m_target->getWorldPosition());

	MathLibrary::Vector2 desiredVelocity = direction * getForce();

	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();

	return steeringForce;
}

void FleeBehaviour::update(Agent* Agent, float deltatime)
{
	if (Agent)
		Agent->addForce(calculateForce(Agent));
}
