#include "Enemy.h"
#include "Game.h"
Enemy::Enemy(float x, float y, float collisionRadius, const char* spriteFilePath, Agent* target, float health, float damage, float maxSpeed, float maxForce)
	: Character(x, y, collisionRadius, spriteFilePath, maxSpeed, maxForce, health, damage)
{
	setTarget(target);

}


void Enemy::update(float deltatime)
{
	Character::update(deltatime);
	if (getWorldPosition().x > Game::getScreenWidth() / 32)
		setWorldPostion(MathLibrary::Vector2(0, getWorldPosition().y));

	if (getWorldPosition().x < 0)
		setWorldPostion(MathLibrary::Vector2(Game::getScreenWidth() / 32, getWorldPosition().y));

	if (getWorldPosition().y > Game::getScreenHeight() / 32)
		setWorldPostion(MathLibrary::Vector2(getWorldPosition().x, Game::getScreenHeight() / 32));

	if (getWorldPosition().y < 0)
		setWorldPostion(MathLibrary::Vector2(getWorldPosition().x, Game::getScreenHeight() / 32));
}

