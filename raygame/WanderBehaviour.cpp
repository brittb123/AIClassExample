#include "WanderBehaviour.h"
#include "Agent.h"

WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	m_circleDistance = 5;
	m_wanderForce = 1;
}

WanderBehaviour::WanderBehaviour(Agent* agent, float Radius, float WanderForces)
{
	m_target = agent;
	m_circleDistance = Radius;
	m_wanderForce = WanderForces;
}

MathLibrary::Vector2 WanderBehaviour::calculateForce(Agent* agent)
{
	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(agent->getWorldPosition() - m_target->getWorldPosition());
	MathLibrary::Vector2 Circle = (agent->getWorldPosition() + direction) * m_circleDistance;
	

	
}
