/*********************
Name: Brent Hoover
Final Project
Purpose: This file thoroughly tests a graph by defining an object from 
the Graph class and calling its member functions
**********************/

#include "main.h"

int main()
{
	
	cout << "\nGraph object defined" << endl;
	Graph graph;
	
	/*
		Testing if graph is empty and getting number of nodes
	*/
	cout << "Testing empty graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl;
	graph.printGraph();
	cout << endl;
	
	/*
		Testing adding nodes to graph
	*/
	cout << "Adding nodes to graph" << endl << endl;
	int value = 10;
	string str = "ABCD";
	for(int i = 0; i < 9; i++)
	{
		cout << "Adding Node " << value << "(\"" << str << "\"): ";
		if(graph.addNode(value, &str))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		value +=10;
	}
	cout << endl;
	
	cout << "Adding nodes with same ids" << endl << endl;
	value = 10;
	for(int i = 0; i < 9; i++)
	{
		cout << "Adding Node " << value << "(\"" << str << "\"): ";
		if(graph.addNode(value, &str))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		value +=10;
	}
	cout << endl;
	
	cout << "Adding nodes with negative ids, ";
	cout << "ids equal to zero, and empty strings" << endl << endl;
	value = -5;
	string emptyStr = "";
	for(int i = 0; i < 6; i++)
	{
		cout << "Adding Node " << value << "(\"" << str << "\"): ";
		if(graph.addNode(value, &str))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		value +=1;
	}
	for(int i = 0; i < 6; i++)
	{
		cout << "Adding Node " << value << "(\"" << emptyStr << "\"): ";
		if(graph.addNode(value, &emptyStr))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		value +=1;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;
	
	/*
		Testing if node exists
	*/
	cout << "Testing if node exists" << endl << endl;
	value = 10;
	for(int i = 0; i < 9; i++)
	{
		cout << "Node " << value << "(\"" << str << "\") Exists: ";
		if(graph.nodeExists(value))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
		value +=10;
	}
	cout << endl;
	
	cout << "Testing if node exists again" << endl << endl;
	value = -3;
	for(int i = 0; i < 7; i++)
	{
		cout << "Node " << value << "(\"" << str << "\") Exists: ";
		if(graph.nodeExists(value))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
		value +=1;
	}
	cout << endl;
	
	/*
		Testing getting data from nodes
	*/
	cout << "Retrieving data from node" << endl << endl;
	value = 10;
	Data data;
	for(int i = 0; i < 9; i++)
	{
		cout << "Get Node " << value << ": ";
		if(graph.getNode(value, &data))
		{
			cout << "True" << "\t\tID: " << data.id << "\tData: " << data.data << endl;
		}
		else
		{
			cout << "False" << "\t\tID: " << data.id << "\tData: " << data.data << endl;
		}
		value +=10;
	}
	cout << endl;
	
	cout << "Retrieving data from node again" << endl << endl;
	value = -3;
	for(int i = 0; i < 7; i++)
	{
		cout << "Get Node " << value << ": ";
		if(graph.getNode(value, &data))
		{
			cout << "True" << "\t\tID: " << data.id << "\tData: " << data.data << endl;
		}
		else
		{
			cout << "False" << "\t\tID: " << data.id << "\tData: " << data.data << endl;
		}
		value +=1;
	}
	cout << endl;
	
	/*
		Testing adding edge between nodes
	*/
	cout << "Adding bi-directional, weighted edges between nodes" << endl << endl;
	int nodeId = 10, edgeId = 20;
	double distance = 6.25;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	edgeId = 60;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	edgeId = 90;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;
	
	/*
		Testing adding edge between nodes
	*/
	cout << "Adding bi-directional, weighted edges between nodes" << endl << endl;
	nodeId = 20, edgeId = 30;
	distance = 7.50;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	edgeId = 50;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 30, edgeId = 40;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	edgeId = 50;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;
	
	/*
		Testing adding edge between nodes
	*/
	cout << "Adding bi-directional, weighted edges between nodes" << endl << endl;
	nodeId = 40, edgeId = 70;
	distance = 8.75;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	edgeId = 80;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 50, edgeId = 70;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 60, edgeId = 70;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;
	
	/*
		Testing adding edge between nodes
	*/
	cout << "Adding edges between nodes by passing negative ids, ";
	cout << "non-existing ids, and matching ids" << endl << endl;
	nodeId = -2; edgeId = 10;
	distance = 10.15;
	for(int i = 0; i < 5; i++)
	{
		cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.addEdge(nodeId, edgeId, distance))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 1;
	}
	cout << endl;
	nodeId = 10; edgeId = -2;
	for(int i = 0; i < 5; i++)
	{
		cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.addEdge(nodeId, edgeId, distance))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		edgeId += 1;
	}
	cout << endl;
	nodeId = 10, edgeId = 10;
	for(int i = 0; i < 5; i++)
	{
		cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.addEdge(nodeId, edgeId, distance))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId += 10;
	}
	cout << endl;
	
	/*
		Testing adding edge between nodes
	*/
	cout << "Adding edges between nodes by passing existing ids ";
	cout << "and negative distances" << endl << endl;
	nodeId = 10, edgeId = 20;
	distance = 12.35;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 20, edgeId = 30;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 30, edgeId = 40;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 40, edgeId = 80;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	nodeId = 80, edgeId = 40;
	cout << "Adding Edge between Nodes " << nodeId << " & " << edgeId << ": ";
	if(graph.addEdge(nodeId, edgeId, distance))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Failure" << endl;
	}
	cout << endl;
	nodeId = 90, edgeId = 20;
	distance = -4;
	for(int i = 0; i < 5; i++)
	{
		cout << "Adding Edge of Distance " << distance << " between Nodes: ";
		if(graph.addEdge(nodeId, edgeId, distance))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		distance += 1;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;

	/*
		Testing if edge exists between nodes
	*/
	cout << "Testing if edge exists between two nodes" << endl << endl;
	nodeId = 10; edgeId = 20;
	for (int i = 0; i < 3; i++)
	{
		cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId += 10;
	}
	nodeId = 60, edgeId = 70;
	for (int i = 0; i < 2; i++)
	{
		cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId -= 20;
	}
	cout << endl;
	
	cout << "Testing if edge exists between two nodes again" << endl << endl;
	nodeId = 10; edgeId = -1;
	for (int i = 0; i < 2; i++)
	{
		cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		edgeId += 1;
	}
	nodeId = -1; edgeId = 10;
	for (int i = 0; i < 2; i++)
	{
		cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 1;
	}
	nodeId = 10, edgeId = 10;
	cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
	cout << endl;
	nodeId = 10, edgeId = 80;
	for (int i = 0; i < 5; i++)
	{
		cout << "Edge between Nodes " << nodeId << " & " << edgeId << " Exists: ";
		if(graph.edgeExists(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId -= 10;
	}
	cout << endl;
	
	/*
		Testing getting edge between nodes
	*/
	cout << "Retrieving weight of edge between nodes" << endl << endl;
	nodeId = 10, edgeId = 20;
	for(int i = 0; i < 3; i++)
	{
		cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
		nodeId += 10;
		edgeId += 10;
	}
	nodeId = 40, edgeId = 80;
	for(int i = 0; i < 2; i++)
	{
		cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
		nodeId += 10;
		edgeId -= 10;
	}
	cout << endl;
	
	cout << "Retrieving weight of edge between nodes again" << endl << endl;
	nodeId = 10; edgeId = -1;
	for (int i = 0; i < 2; i++)
	{
		cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
		edgeId += 1;
	}
	nodeId = -1; edgeId = 10;
	for (int i = 0; i < 2; i++)
	{
		cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
		nodeId += 1;
	}
	nodeId = 10, edgeId = 10;
	cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
	cout << endl;
	nodeId = 10, edgeId = 80;
	for (int i = 0; i < 5; i++)
	{
		cout << "Get Distance between Nodes " << nodeId << " & " << edgeId << ": ";
		distance = graph.getEdge(nodeId, edgeId);
		if(distance == -1)
		{
			cout << "Failure" << endl;
		}
		else
		{
			cout << distance << endl;
		}
		nodeId += 10;
		edgeId -= 10;
	}
	cout << endl;
	
	/*
		Testing deleting edge between nodes
	*/
	cout << "Deleting edge between nodes" << endl << endl;
	nodeId = 10, edgeId = 20;
	for(int i = 0; i < 3; i++)
	{
		cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId += 10;
	}
	nodeId = 60, edgeId = 70;
	for(int i = 0; i < 2; i++)
	{
		cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId -= 20;	
	}
	cout << endl;

	cout << "Deleting edge between nodes by passing negative ids, ";
	cout << "ids equal to zero, and non-existing ids" << endl << endl;
	nodeId = 10, edgeId = -1;
	for(int i = 0; i < 2; i++)
	{
		cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		edgeId += 1;
	}
	nodeId = -1, edgeId = 10; 
	for(int i = 0; i < 2; i++)
	{
		cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 1;
	}
	nodeId = 10, edgeId = 10;
	cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
	cout << endl;
	nodeId = 10, edgeId = 20;
	for(int i = 0; i < 6; i++)
	{
		cout << "Deleting Edge between Nodes " << nodeId << " & " << edgeId << ": ";
		if(graph.removeEdge(nodeId, edgeId))
		{
			cout << "Success" << endl;
		}
		else
		{
			cout << "Failure" << endl;
		}
		nodeId += 10;
		edgeId += 10;	
	}
	cout << endl;	
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;
	
	/*
		Testing deleting nodes from graph
	*/
	cout << "Deleting nodes from graph" << endl << endl;
	nodeId = 10;
	for(int i = 0; i < 5; i++)
	{
		cout << "Deleting Node " << nodeId << ": ";
		if(graph.removeNode(nodeId))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		nodeId += 20;
	}
	cout << endl;
	
	/*
		Testing if graph is empty, getting number of nodes, and 
		displaying connected nodes using Depth First Search
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl << endl;
	graph.printGraph();
	cout << "Displaying connected nodes in graph using Depth First Search" << endl << endl;
	graph.printDFS();
	cout << endl << endl;

	/*
		Testing deleting nodes from graph
	*/
	cout << "Deleting nodes with negative ids, ";
	cout << "ids equal to zero, and non-existing ids" << endl << endl;
	nodeId = -2;
	for(int i = 0; i < 6; i++)
	{
		cout << "Deleting Node " << nodeId << ": ";
		if(graph.removeNode(nodeId))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		nodeId += 1;
	}
	cout << endl;
	nodeId = 10;
	for(int i = 0; i < 5; i++)
	{
		cout << "Deleting Node " << nodeId << ": ";
		if(graph.removeNode(nodeId))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		nodeId += 20;
	}
	cout << endl;
	
	cout << "Deleting remaining nodes from graph" << endl << endl;
	nodeId = 20;
	for(int i = 0; i < 4; i++)
	{
		cout << "Deleting Node " << nodeId << ": ";
		if(graph.removeNode(nodeId))
		{
			cout << "Success" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		else
		{
			cout << "Failure" << "\t\tNode Count: " << graph.getNodeCount() << endl;
		}
		nodeId += 20;
	}
	cout << endl;
	
	/*
		Testing if graph is empty and getting number of nodes
	*/
	cout << "Displaying data in graph" << endl << endl;
	cout << "Empty: ";
	if(graph.isEmpty())
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}
	cout << "Node Count: " << graph.getNodeCount() << endl;
	graph.printGraph();
	cout << endl;

	
	return 0;
}
