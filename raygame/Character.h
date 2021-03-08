#pragma once
#include "Agent.h"
class Character :
	public Agent
{
public:
	Character(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed = 1, float maxForce = 1, float health = 1, float damage = 1);
	virtual float getHealth() { return m_health; }
	virtual float takeDamage(float damage) { return m_health -= damage; }
	virtual float getDamage() { return m_damage; }
	virtual float setDamage(float damage) { return m_damage = damage; }

private:
	float m_health;
	float m_damage;
};

