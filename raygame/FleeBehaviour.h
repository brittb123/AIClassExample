#pragma once
#include "SteeringBehaviour.h"

class Actor;

class FleeBehaviour :
	public SteeringBehaviour
{
public:

	FleeBehaviour();

	FleeBehaviour(Actor* Target, float fleeforce = 1);

	void setTarget(Actor* Target) { m_target = Target; }

	Actor* getTarget(Actor* Target) { return m_target; }

	MathLibrary::Vector2 calculateForce(Agent* agent) override;

	void update(Agent* Agent, float deltatime) override;

private:
	Actor* m_target;

	float m_fleeForce;

};

