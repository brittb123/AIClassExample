#pragma once
#include "SteeringBehaviour.h"
class WanderBehaviour :
	public SteeringBehaviour
{
public:
	WanderBehaviour();

	WanderBehaviour(float CircleRadius);

private:
	float circleRadius;

};

