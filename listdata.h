/*********************
Name: Brent Hoover
Final Project
Purpose: This file defines the structs Weight and Edge
**********************/

#ifndef LIST_DATA_H
#define LIST_DATA_H

struct Weight {
    int id;
	double distance;
};

struct Edge {
	Weight weight;
	Edge *next;
};


#endif // LIST_DATA //
