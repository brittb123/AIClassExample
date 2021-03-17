#pragma once
#include "Enemy.h"
#include "WanderBehaviour.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"

class WanderBehaviour;
class FleeBehaviour;
class SeekBehaviour;

class ComplexEnemy :
	public Enemy
{
public:
	using Enemy::Enemy;

	void start() override;

	void setTarget(Actor* target) override;

	void onCollision(Actor* other) override;

	WanderBehaviour* getWander() { return m_wanderBehaviour; }

	SeekBehaviour* getSeek() { return m_seekBehaviour; }

	FleeBehaviour* getFlee() { return m_fleeBehaviour; }

	

	bool checkTargetInSight(float angle = 2);

	bool checkTargetinRange(float range);

private:

	WanderBehaviour* m_wanderBehaviour;
	SeekBehaviour* m_seekBehaviour;
	FleeBehaviour* m_fleeBehaviour;

};

