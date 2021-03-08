#pragma once
#include "Behaviour.h"
#include <Vector2.h>


class SteeringBehaviour : public Behaviour
{
public:
	virtual MathLibrary::Vector2 calculateForce(Agent* agent) = 0;
	virtual float getForce() { return m_forceScale; }
	virtual float setForce(float ForceScaler) {return m_forceScale = ForceScaler; }

private:
	float m_forceScale = 1;

};
