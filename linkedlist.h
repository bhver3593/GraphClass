/*********************
Name: Brent Hoover
Final Project
Purpose: This is the header file for linkedlist.cpp and contains
the definition of the LinkedList class
**********************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "listdata.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class LinkedList
{
	private:
		Edge *head;
		
		// private members
		void addFirstEdge(Edge*, bool*);
		void addHead(Edge*, bool*);
		void deleteLastEdge(Edge*, bool*);
		void deleteHead(Edge*, Edge*, bool*);
		void deleteEdge(Edge*, Edge*, bool*);
		
	public:
		LinkedList();	
		bool addEdge(int, double);
		bool deleteEdge(int);
		double getEdge(int);
		bool exists(int);
		void clearList();
		void printList();
};


#endif // LINKED_LIST_H //

