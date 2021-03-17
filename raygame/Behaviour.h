#pragma once

class Agent;

class Behaviour
{
public:

	virtual void update(Agent* agent, float deltatime) = 0;
	virtual void draw(Agent* agent) {};
	bool getEnabled() { return m_enabled; }
	void setEnabled(bool enable) { m_enabled = enable; }

private:
	bool m_enabled = true;
};