/*********************
Name: Brent Hoover
Final Project
Purpose: This file contains member functions for the LinkedList class
**********************/

#include "linkedlist.h"

LinkedList::LinkedList()
{
	head = NULL;
}

bool LinkedList::addEdge(int id, double distance)
{
	Edge *newEdge;
	Edge *current = head;
	bool success = false;
	bool flag = true;
	if(id > 0 && distance > 0)
	{
		newEdge = new Edge;
		newEdge->weight.id = id;
		newEdge->weight.distance = distance;
		newEdge->next = NULL;
		if(!head)
		{
			addFirstEdge(newEdge, &success);
		}
		else
		{
			while(current && flag)
			{
				if(id == current->weight.id)
				{
					flag = false;
				}
				current = current->next;
			}
			if(flag)
			{
				addHead(newEdge, &success);
			}
		}
	}
	return success;
}

bool LinkedList::deleteEdge(int id)
{
	Edge *current = head;
	Edge *previous;
	bool success = false;
	if(current && !current->next && id > 0 && id == head->weight.id)
	{
		deleteLastEdge(current, &success);
	}
	while(current && current->next && id > 0 && !success)
	{
		previous = current;
		current = current->next;
		if(id == head->weight.id)
		{
			deleteHead(current, previous, &success);
		}
		else if(id == current->weight.id)
		{
			deleteEdge(current, previous, &success);
		}
	}
	return success;
}

double LinkedList::getEdge(int id)
{
	Edge *current = head;
	double distance = -1;
	bool success = false;
	while(current && id > 0 && !success)
	{
		if(id == current->weight.id)
		{
			distance = current->weight.distance;
			success = true;
		}
		current = current->next;
	}
	return distance;
}

bool LinkedList::exists(int id)
{
	Edge *current = head;
	bool success = false;
	while(current && id > 0 && !success)
	{
		if(id == current->weight.id)
		{
			success = true;
		}
		current = current->next;
	}
	return success;
}

void LinkedList::clearList()
{
	Edge *current = head;
	bool flag = false;
	if(current)
	{
		while(current && current->next)
		{
			head = current->next;
			delete current;
			current = head;
		}
		if(current)
		{
			head = NULL;
			delete current;
		}
	}
}

void LinkedList::printList()
{
	Edge *current = head;
	while(current)
	{
		cout << " --> " << current->weight.id << " (Distance: "
			<< current->weight.distance << ") ";
		current = current->next;
	}
	cout << endl;
}

/*
	private members
*/

void LinkedList::addFirstEdge(Edge *newEdge, bool *success)
{
	head = newEdge;
	*success = true;
}

void LinkedList::addHead(Edge *newEdge, bool *success)
{
	newEdge->next = head;
	head = newEdge;
	*success = true;
}

void LinkedList::deleteLastEdge(Edge *current, bool *success)
{
	head = NULL;
	delete current;
	*success = true;
}

void LinkedList::deleteHead(Edge *current, Edge *previous, bool *success)
{
	head = current;
	delete previous;
	*success = true;
}

void LinkedList::deleteEdge(Edge *current, Edge *previous, bool *success)
{
	previous->next = current->next;
	delete current;
	*success = true;
}















