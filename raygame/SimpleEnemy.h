#pragma once
#include "Enemy.h"

enum EnemyState
{
	WANDER,
	SEEK
};

class WanderBehaviour;

class SeekBehaviour;

class SimpleEnemy :
	public Enemy
{
public:

	using Enemy::Enemy;

	bool checkTargetinSight();

	void onCollision(Actor* other) override;

	void start() override;

	void update(float deltatime) override;

	void setTarget(Actor* target) override;

private:
	EnemyState m_currentstate;
	WanderBehaviour* m_wander;
	SeekBehaviour* m_seek;
};

