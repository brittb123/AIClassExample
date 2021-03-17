#pragma once
#include "Decision.h"
class ABDecision :
	public Decision
{
public:
	///<summary>
	///</summary>
	ABDecision(Decision* leftchild = nullptr, Decision* rightchild = nullptr);

	///<summary>
	/// Checks the decisions and the transitions
	///</summary>
	virtual void makeDecision(Agent* agent, float deltatime) override;

	///<summary>
	///</summary>
	virtual bool checkDecision(Agent* agent, float deltatime) { return false; }

private:
	Decision* m_leftchild;
	Decision* m_rightchild;

};

