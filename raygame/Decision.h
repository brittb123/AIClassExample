#pragma once

class Agent;

class  Decision 
{
public:
	///<summary>
	/// A base class for all decisions
	///</summary>
	virtual void makeDecision(Agent* agent, float deltatime) = 0;

};