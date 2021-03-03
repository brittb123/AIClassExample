#pragma once
#include "SteeringBehaviour.h"

class WanderBehaviour :
	public SteeringBehaviour
{
public:
	WanderBehaviour();

	WanderBehaviour(Agent* Target, float Radius, float WanderForces);

	void setAngle();

	MathLibrary::Vector2 calculateForce(Agent* Target) override;
	
	void update(float deltatime);

private:
	float circleRadius;

	Agent* m_target;

	float m_wanderForce;
};

