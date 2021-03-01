#include "Agent.h"

Agent::Agent() : Actor()
{
	m_force = { 0, 0 };
	m_maxForce = 1;
}

Agent::Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce) : Actor(x, y, icon, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce) : Actor(x, y, collisionRadius, sprite, maxSpeed)
{
	m_maxForce = maxForce;
}

Agent::Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce) : Actor(x, y, collisionRadius, spriteFilePath, maxSpeed)
{
	m_maxForce = maxForce;
}


void Agent::update(float deltatime)
{
	m_force = { 0, 0 };

	// TO DO:
	//Update  Forces

	setVelocity(getVelocity() + m_force * deltatime);

	Actor::update(deltatime);
}

///<paramname="Force">A force that is to be added to the current force</param>
void Agent::addForce(MathLibrary::Vector2 Force)
{
	// Adds the force to the current force
	m_force = m_force + Force;

	if (m_force.getMagnitude() > getmaxForce())
	{
		m_force = m_force.getNormalized() * getmaxForce();
	}
}