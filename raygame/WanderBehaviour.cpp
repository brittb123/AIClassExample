#include "WanderBehaviour.h"

WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	circleRadius = 5;
	m_wanderForce = 1;
}

WanderBehaviour::WanderBehaviour(Agent* Target, float Radius, float WanderForces)
{
	m_target = Target;
	circleRadius = Radius;
	m_wanderForce = WanderForces;
}

void WanderBehaviour::setAngle()
{



}
