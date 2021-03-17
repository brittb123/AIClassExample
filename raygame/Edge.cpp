#include "Edge.h"
#include <raylib.h>
#include "Node.h"

Edge::Edge(Node* node1, Node* node2) : Actor(0, 0, 0, ' ', 0)
{
	connectednode1 = node1;
	connectednode2 = node2;
}

void Edge::draw()
{
	DrawLine(getWorldPosition().x * 32, getWorldPosition().y * 32,
		connectednode2->getWorldPosition().x * 32, connectednode2->getWorldPosition().y * 32, WHITE);
}

void Edge::update(float deltatime)
{
	Actor::update(deltatime);

	setWorldPostion(connectednode1->getWorldPosition());
}
