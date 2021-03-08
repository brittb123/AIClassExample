#pragma once
#include "Actor.h"
#include <vector>

class Behaviour;

class Agent : public Actor
{
public:
	Agent();

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    /// <param name="maxForce">The force applied to a object of the A.I</param>
    Agent(float x, float y, float collisionRadius, char icon, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    Agent(float x, float y, float collisionRadius, Sprite* sprite, float maxSpeed, float maxForce);

    /// <param name="x">Position on the x axis</param>
    /// <param name="y">Position on the y axis</param>
    /// <param name="icon">The symbol that will appear when drawn</param>
    Agent(float x, float y, float collisionRadius, const char* spriteFilePath, float maxSpeed, float maxForce);

    void update(float deltatime) override;
    
    float getmaxForce() { return m_maxForce; }

    float setmaxForce(float maxForce) { m_maxForce = maxForce; }

    void addForce(MathLibrary::Vector2 Force);

    void addBehaviour(Behaviour* behaviour);

    template<typename BehaviourType>
    BehaviourType* getBehaviour();


private:
   
	MathLibrary::Vector2 m_force;
	float m_maxForce;
	std::vector<Behaviour*> m_behaviours;
};

template<typename BehaviourType>
inline BehaviourType* Agent::getBehaviour()
{
    for (int i = 0; i < m_behaviours.size(); i++)
    {
        BehaviourType* Behaviour = dynamic_cast<BehaviourType*>(m_behaviours[i]);
        
        if (Behaviour)
            return Behaviour;
    }
    return nullptr;
}
