//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
// Class Description: This is the header file for graph.
//		All the methods and classes are declared here

#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "MinHeap.h"

using namespace std;

class Graph {
private:
	class LinkedList* table; //table will be an array of linkedlist
	int tableSize;	//to keep track number of elements in the array

public:
	
	Graph(); //Constructor for NULL case
	Graph(int); //Constructor

	//All methods used in Graph.cpp
	void checkGraph();
	void checkPath(string, string);
	void checkLength(string, string, string);
	void checkInvalid(string, string);
	bool checkBounds(string, string);
	void addNode(string,int);
	void addEdge(string,string,int);
	void shortestPath(string, string);
	void shortestLength(string, string, string);
	void printGraph();
};
