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

	// Take the result of the dot and puts it through cosine to get the angle of the projection
	float angle = acos(Dot);

	// If the angle is greater than zero then the statement returns true 
	if (angle > 0)
		return true;

	return false;
}

void SimpleEnemy::onCollision(Actor* other)
{
	// Checks if the enemy is colliding with the target
	if (checkCollision(Enemy::getTarget()))
	{
		// The enemy is then attempted to be casted as a Character pointer
		Character* enemy = dynamic_cast<Character*>(other);

		// If the cast is passed then the target takes one damage
		if (enemy)
			enemy->takeDamage(1);

		// If the target is below or equal to 0 then the target is set to null
		if (enemy->getHealth() <= 0)
			SimpleEnemy::setTarget(nullptr);
	}
}

// A start for the simple enemy class
void SimpleEnemy::start()
{
	// Calls the basic enemy start
	Enemy::start();

	// sets the current state to be set to wonder
	m_currentstate = WANDER;

	// Sets a seek pointer to be seek for quick access without going through the entire list
	m_seek = getBehaviour<SeekBehaviour>();

	// Sets a wander pointer to use without going through the entire list of behaviours
	m_wander = getBehaviour<WanderBehaviour>();

	// Sets the Target with the overloaded function with the enemy's m_target
	setTarget(Enemy::getTarget());

}

void SimpleEnemy::update(float deltatime)
{
	// A switch statement that goes off by the check target in sight
	switch (checkTargetinSight())
	{
	// When the case is true then Wander is set to equal 0 and seek is set to be the current state 
	case true:
		WANDER == 0;
		SEEK == 1;
		m_currentstate == SEEK;
		break;

		// The default case is set to be Wander eqauling 1 and the current state  to be set as Wander until player is in enemy's sight
	default:
		WANDER == 1;
		SEEK == 0;
		m_currentstate == WANDER;
		break;

	}
	Enemy::update(deltatime);
}

void SimpleEnemy::setTarget(Actor* target)
{
	Enemy::setTarget(target);
	m_seek->setTarget(target);
}
