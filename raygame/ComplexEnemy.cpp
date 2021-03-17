#include "ComplexEnemy.h"
#include "Player.h"

void ComplexEnemy::start()
{
	Enemy::start();

	m_wanderBehaviour = getBehaviour<WanderBehaviour>();
	m_seekBehaviour = getBehaviour<SeekBehaviour>();
	m_fleeBehaviour = getBehaviour<FleeBehaviour>();

	setTarget(Enemy::getTarget());
}

void ComplexEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_fleeBehaviour->setTarget(target);
	m_seekBehaviour->setTarget(target);

}

void ComplexEnemy::onCollision(Actor* other)
{
	Enemy::onCollision(other);

	Player* player = dynamic_cast<Player*>(other);

	if (player) 
	{
		player->takeDamage(getDamage());

		if (player->getHealth() <= 0)
		{
			setTarget(nullptr);
		}
	}
		
}
