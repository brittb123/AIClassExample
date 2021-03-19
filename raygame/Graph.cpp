#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <raylib.h>
#include <deque>

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
	start->visited = true;
	Node* current = start;

	std::deque<Node*> queue;
	queue.push_front(start);

	while (!queue.empty())
	{
		current = queue[0];
		queue.pop_front();

		if (current == goal)
		{
			current->color - ColorToInt(YELLOW);
			return;

		}

		for (int i = 0; i < current->edge.size(); i++)
		{
			Node* currentEdge = nullptr;
			if (current == current->edge[i]->connectednode2)
				currentEdge = current->edge[i]->connectednode1;
			else
				currentEdge = currentEdge->edge[i]->connectednode2;

			if(!currentEdge->visited)
			{
				currentEdge->color = ColorToInt(RED);
				currentEdge->visited = true;
				queue.push_back(currentEdge);
			}
		}
	}

}

std::vector<Node*> Graph::dijkstra(int startX, int startY, int goalX, int goalY)
{
	Node* StartNode = getNode(startX, startY);

	Node* GoalNode = getNode(goalX, goalY);
	if (!StartNode || !GoalNode)
		return;

	StartNode->color = ColorToInt(GREEN);

	Node* Current = StartNode;

	std::deque<Node*> open;

	std::deque<Node*> closed;

	open.push_front(StartNode);

	while (open.size() != 0)
	{

		// Sort items by g score

		open.push_front(Current);

		if (Current == GoalNode)
		{
			GoalNode->color = ColorToInt(RED);
			return std::vector<Node*>();
		}

		open.pop_front();

		closed.push_front(Current);

		for (int i = 0; i < Current->edge.size(); i++)
		{
			Node* EndEdge = Current->e;
		}
	}

	return std::vector<Node*>();
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
