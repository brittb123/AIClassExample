#include "SimpleEnemy.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"


bool SimpleEnemy::checkTargetinSight()
{
	// Checks if the target is null
	if (Enemy::getTarget() == nullptr)
		return false;

	// Calculate the distance and the direction of the target
	MathLibrary::Vector2 Distance = Enemy::getTarget()->getWorldPosition() - getWorldPosition();
	
	// Gets the dot product of the target and the enemy calling this function
	float Dot = MathLibrary::Vector2::dotProduct(Enemy::getTarget()->getForward(), Distance);

	float angle = acos(Dot);

	if (angle > 0)
		return true;

	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	if (checkCollision(Enemy::getTarget()))
	{
		Character* enemy = dynamic_cast<Character*>(other);

		if (enemy)
			enemy->takeDamage(1);

		if (enemy->getHealth() < 0)
			SimpleEnemy::setTarget(nullptr);
	}
}

void SimpleEnemy::start()
{
	Enemy::start();

	m_currentstate = WANDER;

	m_seek = getBehaviour<SeekBehaviour>();

	m_wander = getBehaviour<WanderBehaviour>();

	setTarget(Enemy::getTarget());

}

void SimpleEnemy::update(float deltatime)
{
	switch (checkTargetinSight())
	{
	case true:
		WANDER == 0;
		SEEK == 1;
		break;

	default:
		WANDER == 1;
		SEEK == 0;
		break;
	}
	Enemy::update(deltatime);
}

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}
