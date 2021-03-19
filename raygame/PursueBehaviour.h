#pragma once
#include "SteeringBehaviour.h"

class Actor;

class PursueBehaviour :
    public SteeringBehaviour
{
    PursueBehaviour();
    PursueBehaviour(Actor* tagret, float pursueForce = 1);

    Actor* getTarget() { return m_target; }
    Actor* setTarget(Actor* target) { m_target = target; }

    MathLibrary::Vector2 calculateForce(Agent* agent) override;
    void update(Agent* agent, float deltaTime) override;

private:
    Actor* m_target;
    float m_pursueForce;



};

