/*********************
Name: Brent Hoover
Final Project
Purpose: This file defines the structs Data and Node
**********************/

#ifndef DATA_H
#define DATA_H

#include "linkedlist.h"
#include <string>
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
	Data data;
	LinkedList list;
	bool visited;
};


#endif // DATA_H //
