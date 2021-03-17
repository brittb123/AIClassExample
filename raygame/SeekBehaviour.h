#pragma once 
#include "SteeringBehaviour.h"

class Actor;

class SeekBehaviour : public SteeringBehaviour
{
public:
	SeekBehaviour();
	SeekBehaviour(Actor* Target, float SeekForce = 1);

	Actor* getTarget() { return m_target; }
	void setTarget(Actor* Target) { m_target = Target; }

	MathLibrary::Vector2 calculateForce(Agent* agent) override;
	void update(Agent* Agent, float deltatime) override;

private:

	Actor* m_target;

};
