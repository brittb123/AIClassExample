#include "WanderBehaviour.h"
#include "Agent.h"

WanderBehaviour::WanderBehaviour()
{
	m_target = nullptr;
	m_circleDistance = 5;
	setForce(1);
}

WanderBehaviour::WanderBehaviour(Actor* target, float seekForce)
{
	m_target = target;
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

	MathLibrary::Vector2 Circle = agent->getForward() * m_circleDistance;

	MathLibrary::Vector2 CirclePlaced = Circle * getForce();

	m_angle += (rand() * m_angle) - (m_angle * .5);

	MathLibrary::Vector2 direction = MathLibrary::Vector2(cos(m_angle), sin(m_angle)).getNormalized();

	/*MathLibrary::Vector2 Random = MathLibrary::Vector2(cos(rand()), sin(rand()));*/

	MathLibrary::Vector2 DesiredVel = (direction * m_circleDistance) + Circle;
	
	MathLibrary::Vector2 Force = DesiredVel + CirclePlaced;

	Force = Force.getNormalized();

	return Force;
}

void WanderBehaviour::update(Agent* agent, float deltatime)
{
	if (agent)
		agent->addForce(calculateForce(agent));
}

