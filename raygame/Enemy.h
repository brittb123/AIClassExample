#pragma once
#include "Agent.h"
#include "Character.h"
class Enemy :
	public Character
{
public:
  /// <param name="x">Position on the x axis</param>
  /// <param name="y">Position on the y axis</param>
  /// <param name="icon">The symbol that will appear when drawn</param>
	Enemy(float x, float y, float collisionRadius, const char* spriteFilePath, Agent* target, float health = 1, float damager = 1, float maxSpeed = 1, float maxForce = 1);

    virtual Actor* getTarget() { return m_target; }

    virtual void setTarget(Actor* Target) { m_target = Target; }

    void update(float deltatime) override;

    void setTarget(Agent* agent) { m_target = agent; }

private:
    Actor* m_target;
};

