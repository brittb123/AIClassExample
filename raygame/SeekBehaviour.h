
#include "SteeringBehaviour.h"
class SeekBehaviour :
	public SteeringBehaviour
{
public:
	SeekBehaviour() { m_target = nullptr; }

	SeekBehaviour(Agent* Target) { m_target = Target; }

	void setTarget(Agent* Target) { m_target = Target; }

	Agent* getTarget() { return m_target; }

	MathLibrary::Vector2 calculateForce(Agent* agent) override;

	void update(Agent* Agent, float deltatime) override;

private:

	Agent* m_target;
};
