#pragma once
#include "Behaviour.h"

class Decision;

class DecisionBehaviour :
	public Behaviour

{
public:
	DecisionBehaviour(Decision* root) {};

	void update(Agent* agent, float deltatime) override;

private:
	Decision* m_root;
};

