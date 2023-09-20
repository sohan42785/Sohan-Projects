//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
// Class Description: This implements the methods declared in LinkedList.h

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "LinkedList.h"

using namespace std;

//Constructor
LinkedList::LinkedList() {
	head = NULL;
	name = "";
}

//Prints elements in of each linkedList
void LinkedList::printList(LinkedList list) {
	Project* ptr = list.head;
	//if list is empty
	if (ptr == NULL) {
		cout << "No adjacent nodes" << endl;
		cout << endl;
	}
	//otherwise print all the nodes in the linkedlist
	else {
		while (ptr != NULL) {
			cout << "To: " << ptr->projName << " with weight " << ptr->weight << endl;
			ptr = ptr->next;
		}
		cout << endl;
	}
}
