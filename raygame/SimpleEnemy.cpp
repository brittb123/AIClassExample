#include "SimpleEnemy.h"
#include "SeekBehaviour.h"
#include "WanderBehaviour.h"


bool SimpleEnemy::checkTargetinSight()
{
	if (Enemy::getTarget() == nullptr)
		return false;

	MathLibrary::Vector2 Distance = Enemy::getTarget()->getWorldPosition() - this->getWorldPosition();



	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	if (checkCollision(Enemy::getTarget()))
		Enemy::getTarget()->Character::takeDamage(1);


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

}

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}
