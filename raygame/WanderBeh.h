#pragma once
#include "ABDecision.h"

class WanderBeh :
	public ABDecision
{
public:
	using ABDecision::ABDecision;

	void makeDecision(Agent* agent, float deltatime) override;
};

