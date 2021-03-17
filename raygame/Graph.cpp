#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <raylib.h>

Graph::Graph(int width, int height, int nodeSize, int nodeSpacing)
{
	m_width = width;
	m_height = height;

	createGraph(nodeSize, nodeSpacing);
}

void Graph::draw()
{
	for (int i = 0; i < m_nodes.size(); i++)
		m_nodes[i]->draw();
}

void Graph::update(float deltatime)
{
	Actor::update(deltatime);

	for (int i = 0; i < m_nodes.size(); i++)
		m_nodes[i]->update(deltatime);
}

void Graph::BFS(int startX, int startY, int goalX, int goalY)
{
	Node* start = getNode(startX, startY);
	Node* goal = getNode(goalX, goalY);

	if (!start || !goal)
		return;

	start->color = ColorToInt(GREEN);
}

Node* Graph::getNode(int xPos, int yPos)
{
	if (xPos < 0 || yPos < 0 || xPos > m_width || yPos > m_height)
		return nullptr;

	for (int i = 0; i < m_nodes.size(); i++)
	{
		if (m_nodes[i]->graphPosition == MathLibrary::Vector2(xPos, yPos))
			return m_nodes[i];
	}
	return nullptr;
}

void Graph::createGraph(int nodeSize, int nodeSpacing)
{
	float xPos = 0;
	float yPos = 0;

	for (int i = 0; i < m_width * m_height; i++)
	{
		Node* current = new Node(xPos, yPos, nodeSize);

		MathLibrary::Vector2 NodeLocalPos = { xPos * nodeSpacing, yPos * nodeSpacing };

		current->setLocalPosition(NodeLocalPos);

		addChild(current);

		m_nodes.push_back(current);
		
		for (int j = 0; j < m_nodes.size(); j++)
		{
			MathLibrary::Vector2 Displace = m_nodes[i]->graphPosition - current->graphPosition;
			
			if (Displace.getMagnitude() <= 1.42 && Displace.getMagnitude() > 0)
			{
				Edge* currentEdge = new Edge(m_nodes[i], current);
				current->edge.push_back(currentEdge);
				m_nodes[i]->edge.push_back(currentEdge);
			}
		}

		xPos++;

		if (xPos >= m_width)
		{
			xPos = 0;
			yPos++;
		}
	}
}
