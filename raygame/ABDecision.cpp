#include "ABDecision.h"

ABDecision::ABDecision(Decision* leftchild, Decision* rightchild)
{
	m_leftchild = leftchild;
	m_rightchild = rightchild;
}

///<summary>
///Either child is checked to be null then a decision is made based on the childer of the current parent
///</summary>
void ABDecision::makeDecision(Agent* agent, float deltatime)
{

	// If returns true and left isnt null this make decision is used
	if (checkDecision(agent, deltatime))
	{
		if (m_leftchild)
			m_leftchild->makeDecision(agent, deltatime);

		else
		{
			if (m_rightchild)
				m_rightchild->makeDecision(agent, deltatime);
		}

	}
}
