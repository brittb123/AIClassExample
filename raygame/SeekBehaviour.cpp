#include "SeekBehaviour.h"
#include "Agent.h"
#include "Actor.h"

SeekBehaviour::SeekBehaviour()
{
	m_target = nullptr;
	m_seekForce = 1;
}

SeekBehaviour::SeekBehaviour(Actor* Target, float Seekforce)
{
	m_target = Target;
	m_seekForce = Seekforce;
}

MathLibrary::Vector2 SeekBehaviour::calculateForce(Agent* agent)
{

	MathLibrary::Vector2 direction = MathLibrary::Vector2::normalize(m_target->getWorldPosition() - agent->getWorldPosition());

	MathLibrary::Vector2 desiredVelocity = direction * m_seekForce;

	MathLibrary::Vector2 steeringForce = desiredVelocity - agent->getVelocity();

	return steeringForce;
}

void SeekBehaviour::update(Agent* Agent, float deltatime)
{
	if (Agent)
		Agent->addForce(calculateForce(Agent));



}
