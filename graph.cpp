/*********************
Name: Brent Hoover
Final Project
Purpose: This file contains member functions for the Graph class
**********************/

#include "graph.h"

Graph::Graph()
{
	graph = new vector<Node*>;
	count = 0;
}

Graph::~Graph()
{
	Node *tempNode;
	for(int i = graph->size()-1; i >= 0; i--)
	{
		tempNode = graph->at(i);
		tempNode->list.clearList();
		graph->pop_back();
	}
	delete graph;
}

bool Graph::isEmpty()
{
	return graph->empty();
}

bool Graph::addNode(int id, string *data)
{
	Node *newNode;
	Node *tempNode;
	bool success;
	if(id > 0 && *data != "")
	{
		newNode = new Node;
		newNode->data.id = id;
		newNode->data.data = *data;
		success = true;
		for(int i = 0; i < graph->size() && success; i++)
		{
			tempNode = graph->at(i);
			if(id == tempNode->data.id)
			{
				success = false;
			}
		}
		if(success)
		{
			graph->push_back(newNode);
			count++;
		}
	}
	return success;
}

bool Graph::removeNode(int id)
{
	Node *tempNode;
	bool success = false;
	for(int i = 0; i < graph->size() && id > 0; i++)
	{
		tempNode = graph->at(i);
		if(id == tempNode->data.id)
		{
			tempNode->list.clearList();
			graph->erase(graph->begin() + i);
			i--;
			count--;
			success = true;
		}
		else if(tempNode->list.deleteEdge(id))
		{
			success = true;
		}
	}
	return success;
}

bool Graph::getNode(int id, Data *data)
{
	Node *tempNode;
	data->id = -1;
	data->data = "";
	bool success = false;
	for(int i = 0; i < graph->size() && id > 0 && !success; i++)
	{
		tempNode = graph->at(i);
		if(id == tempNode->data.id)
		{
			data->id = tempNode->data.id;
			data->data = tempNode->data.data;
			success = true;
		}
	}
	return success;
}

bool Graph::nodeExists(int id)
{
	Node *tempNode;
	bool success = false;
	for(int i = 0; i < graph->size() && id > 0 && !success; i++)
	{
		tempNode = graph->at(i);
		if(id == tempNode->data.id)
		{
			success = true;
		}
	}
	return success;
}

int Graph::getNodeCount()
{
	return count;
}

bool Graph::addEdge(int nodeId, int edgeId, double distance)
{

	Node *tempNode, *node;
	Node *tempEdge, *edge;
	bool flag = false, flag2 = false;
	bool success = false;
	if(nodeId > 0 && edgeId > 0 && nodeId != edgeId && distance > 0)
	{
		for(int i = 0; i < graph->size(); i++)
		{
			tempNode = graph->at(i);
			tempEdge = graph->at(i);
			if(nodeId == tempNode->data.id && !flag)
			{
				node = tempNode;
				flag = true;
			}
			if(edgeId == tempEdge->data.id && !flag2)
			{
				edge = tempEdge;
				flag2 = true;
			}
		}
		if(flag && flag2)
		{
			if(node->list.addEdge(edgeId, distance) && edge->list.addEdge(nodeId, distance))
			{
				success = true;
			}
		}
	}
	return success;
}

bool Graph::removeEdge(int nodeId, int edgeId)
{
	Node *tempNode;
	Node *tempEdge;
	bool flag = false, flag2 = false;
	bool success = false;
	if(nodeId > 0 && edgeId > 0 && nodeId != edgeId)
	{
		for(int i = 0; i < graph->size(); i++)
		{
			tempNode = graph->at(i);
			tempEdge = graph->at(i);
			if(nodeId == tempNode->data.id && tempNode->list.deleteEdge(edgeId) && !flag)
			{
				flag  = true;
			}
			if(edgeId == tempEdge->data.id && tempEdge->list.deleteEdge(nodeId) && !flag2)
			{
				flag2 = true;
			}
		}
		if(flag && flag2)
		{
			success = true;
		}
	}
	return success;
}

double Graph::getEdge(int nodeId, int edgeId)
{
	Node *tempNode;
	double distance = -1;
	bool flag = false;
	if(nodeId > 0 && edgeId > 0 && nodeId != edgeId)
	{
		for(int i = 0; i < graph->size() && !flag; i++)
		{
			tempNode = graph->at(i);
			if(nodeId == tempNode->data.id)
			{
				distance = tempNode->list.getEdge(edgeId);
				flag = true;
			}
		}
	}
	return distance;
}

bool Graph::edgeExists(int nodeId, int edgeId)
{
	Node *tempNode;
	bool success = false;
	if(nodeId > 0 && edgeId > 0 && nodeId != edgeId)
	{
		for(int i = 0; i < graph->size() && !success; i++)
		{
			tempNode = graph->at(i);
			if(nodeId == tempNode->data.id && tempNode->list.exists(edgeId))
			{
				success = true;
			}
		}
	}
	return success;
}

void Graph::printDFS()
{
	Node *currentNode;
	Node *tempNode;
	int edgeId;
	vector<Node*> stack;
	vector<Node*>::iterator iter;
	bool flag = false;
	if(!graph->empty())
	{
		currentNode = graph->at(0);
		cout << "Node " << currentNode->data.id << "(\"" 
			<< currentNode->data.data << "\")" << endl;
		currentNode->visited = true;
		stack.push_back(currentNode);
		
		for(int i = 0; i < graph->size() && !flag; i++)
		{
			tempNode = graph->at(i);
			edgeId = tempNode->data.id;
			if(currentNode->list.exists(edgeId) && !tempNode->visited)
			{
				currentNode = tempNode;
				flag = true;
			}
		}
	}
	
	while(!stack.empty())
	{
		if(!currentNode->visited)
		{
			cout << "Node " << currentNode->data.id << "(\"" 
				<< currentNode->data.data << "\")" << endl;
			currentNode->visited = true;
			stack.push_back(currentNode);
		}
		flag = false;
		for(int i = 0; i < graph->size() && !flag; i++)
		{
			tempNode = graph->at(i);
			edgeId = tempNode->data.id;
			if(currentNode->list.exists(edgeId) && !tempNode->visited)
			{
				currentNode = tempNode;
				flag = true;
			}
		}
		if(!flag)
		{
			stack.pop_back();
			iter = stack.end()-1;
			currentNode = *iter;
		}
	}
	
	for(int i = 0; i < graph->size(); i++)
	{
		currentNode = graph->at(i);
		currentNode->visited = false;
	}
}

/*
	dummy print function that displays adjacency list
*/
void Graph::printGraph()
{
	Node *node;
	if(graph->empty())
	{
		cout << "Graph is empty" << endl;
	}
	else
	{
		for(int i = 0; i < graph->size(); i++)
		{
			node = graph->at(i);
			cout << "Node " << node->data.id << "(\"" << node->data.data << "\")"; 
			node->list.printList();
			cout << endl;
		}
	}
}

















































