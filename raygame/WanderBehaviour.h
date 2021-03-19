#pragma once
#include "SteeringBehaviour.h"


class Actor;

class WanderBehaviour :
	public SteeringBehaviour
{
public:
	WanderBehaviour();

	WanderBehaviour(Actor* target, float seekForce = 1);

	WanderBehaviour(Agent* agent, float CircleDistance, float WanderForces);

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	
	void update(Agent* agent, float deltatime) override;

private:
	float m_circleDistance;

	Actor* m_target;

	float m_angle;

};



