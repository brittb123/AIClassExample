#pragma once
#include "SteeringBehaviour.h"

class Actor;

class WanderBehaviour :
	public SteeringBehaviour
{
public:
	WanderBehaviour();

	WanderBehaviour(Agent* agent, float CircleDistance, float WanderForces);

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	
	void update(Agent* agent, float deltatime) override;

	void draw(Agent* agent) override;

private:
	float m_circleDistance;

	Agent* m_target;


};

