#include "Character.h"

Character::Character(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce, float health, float damage) :
    Agent(x, y, collisionRadius, spriteFilePath, maxSpeed, maxForce)
{
    m_health = health;
    m_damage = damage;
}
