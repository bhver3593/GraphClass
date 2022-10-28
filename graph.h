/*********************
Name: Brent Hoover
Final Project
Purpose: This is the header file for graph.cpp and contains
the definition of the Graph class
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include "listdata.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Graph
{
	private:
		vector<Node*> *graph;
		int count;
		
	public:
		Graph();
		~Graph();
		bool isEmpty();
		bool addNode(int, string*);
		bool removeNode(int);
		bool getNode(int, Data*);
		bool nodeExists(int);
		int getNodeCount();
		bool addEdge(int, int, double);
		bool removeEdge(int, int);
		double getEdge(int, int);
		bool edgeExists(int, int);
		void printDFS();
		
		// dummy print function
		void printGraph();
			
};


#endif // GRAPH_H // 
