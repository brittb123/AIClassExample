#pragma once

class Agent;

class Behaviour
{
public:
	virtual void update(Agent* agent, float deltatime) = 0;
	virtual void draw(Agent* agent) {};
};