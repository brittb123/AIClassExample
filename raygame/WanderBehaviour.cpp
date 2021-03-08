#include "WanderBehaviour.h"
#include "Agent.h"

WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	m_circleDistance = 5;
	setForce(1);
}

WanderBehaviour::WanderBehaviour(Agent* agent, float Radius, float WanderForces)
{
	m_target = agent;
	m_circleDistance = Radius;
	setForce(WanderForces);
}

MathLibrary::Vector2 WanderBehaviour::calculateForce(Agent* agent)
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(agent->getWorldPosition() - m_target->getWorldPosition());

	MathLibrary::Vector2 Circle = (agent->getWorldPosition() + direction) * m_circleDistance;
	
	
}
