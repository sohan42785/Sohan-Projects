//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
// Class Description: Creates the methods for linkedList to be implemented in the Graph

#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//The basic information that each node holds
struct Project {
	int weight;
	int index;
	string projName;
	struct Project* next;
};


class LinkedList {
private:

public:
	LinkedList(); //Constructor

	struct Project* head;
	string name;

	void printList(LinkedList); //prints the elements in the linkedList
};


#endif