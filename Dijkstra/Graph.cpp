//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
// Class Description: Finds the shortest path/length to the finish node from the start

#include <iostream>
#include <iomanip>
#include <string>
#include "Graph.h"

using namespace std;

//Constructor
Graph::Graph() {
	table = NULL;	//initializes the table to NULL if there are no elememts
}

//Second Constructor
Graph::Graph(int n) {
	table = new LinkedList[n];	//Creates an array of linkedLists
	//Sets the head value equal to NULL for each linked list
	for (int i = 0; i < n; i++) {
		table[i].head = NULL;
	}
	tableSize = n;
}

//Methods checks to see if the nodes where created
void Graph::checkGraph() {
	//if the table is NULL throw an error, otherwise print the graph contents
	if (table == NULL) {
		cout << "Error: graph not initialized" << endl;
	}
	else {
		printGraph();
	}
}

//Called to check for any errors before running the shortestLength method
void Graph::checkLength(string start, string finish, string check) {
	if (table == NULL) {
		//checks if graph is initialized
		cout << "Error: graph not initialized" << endl;
	}
	else if (checkBounds(start, finish)) {
		//if the called nodes were never created then return an error
		cout << "Error: one or more invalid nodes" << endl;
	}
	else {
		//if no errors run the method
		shortestLength(start, finish, check);
	}
}

//Method is run when the incorrect "shortest" method was called
void Graph::checkInvalid(string start, string finish) {
	if (table == NULL) {
		//checks if graph was initialized
		cout << "Error: graph not initialized" << endl;
	}
	else if (checkBounds(start, finish)) {
		//if called nodes were never created then return an error
		cout << "Error: one or more invalid nodes" << endl;
	}
	else {
		//The last error call
		cout << "Error: unknown print command" << endl;
	}
}

//Checks if passed Projects were created during fileread 
bool Graph::checkBounds(string start, string finish) {
	bool real1 = false;
	bool real2 = false;
	//runs through each table array index to check if project was created
	for (int i = 0; i < tableSize; i++) {
		//if node was created for both "start" and "finish" then make variables true 
		if (table[i].name == start) {
			real1 = true;
		}
		if (table[i].name == finish) {
			real2 = true;
		}
	}
	//if variables are in bound then return false so error message isn't run
	if (real1 && real2) {
		return false;
	}
	else {
		return true;
	}
}

//adds the node into the index name
void Graph::addNode(string pName, int index) {
	table[index].name = pName;
}

//Stores the weight from the start to finish node using a linkedlist
void Graph::addEdge(string start, string finish, int w) {
	//add the nodes in as a project into the linkedlist
	Project* temp = new Project();
	Project* ptr;
	//create the Project by getting index info from array
	for (int i = 0; i < tableSize; i++) {
		if (table[i].name == finish) {
			temp->index = i;
			temp->projName = finish;
			temp->weight = w;
		}
	}
	//locates the correct index by searching through for loop
	for (int i = 0; i < tableSize;i++) {
		if (table[i].name == start) {
			if (table[i].head == NULL) {
				//If the head of the table is empty then make temp the head
				table[i].head = temp;	
				table[i].head->next = NULL;
			}
			else {
				ptr = table[i].head; //set ptr equal to the head of the list
				//iterate through the list until an empty node is located
				while (ptr != NULL) {
					if (ptr->next == NULL) {
						//set the empty node to temp and set the next node to NULL
						ptr->next = temp;
						temp->next = NULL;
					}
					ptr = ptr->next; //this sets ptr equal to next node in the linkedlist
				}
			}
		}
	}
}

//prints all elements of linkedlists
void Graph::printGraph() {
	cout << "The Graph Content:" << endl;
	cout << "-------------------" << endl;
	//goes through the linkedlist in each index and prints the list
	for (int i = 0; i < tableSize; i++) {
		cout << "From: " << table[i].name << endl;
		table->printList(table[i]);
	}
}

//calculates the shortest path and distance from start to finish
void Graph::shortestLength(string start, string finish, string check) {
	//create arrays for distance and pi
	int index = 0;
	int* d = new int[tableSize];
	Project* pi = new Project[tableSize];
	int* s = new int[tableSize];
	Object var;

	//initialize distance to zero and pi to 10000 for each index
	for (int i = 0; i < tableSize; i++) {
		//set index equal to the start node
		if (table[i].name == start) {
			index = i;
		}
		d[i] = 10000;
		pi[i].projName = "";
		s[i] = 0;
	}
	//create a new minHeap Object
	MinHeap* heap = new MinHeap();
	heap->create(tableSize); //initializes a linkedlist with node elements
	d[index] = 0; //sets distance for start node to 0
	//inserts each node into the minheap linkedlist one by one
	for (int i = 0; i < tableSize; i++) {
		heap->minHeapInsert(table[i].name, d[i]);
	}
	heap->buildMin(tableSize); //this turns the linkedlist into a minheap passing the table size
	//contines as long as there are still nodes in the minheap
	while (heap->checkEmpty() == false) {
		var = heap->extractMin(); //removes the smallest node and sets var equal to that node
		//this loop locates the index of the var Object
		for (int i = 0; i < tableSize; i++) {
			if (table[i].name == var.projName) {
				index = i;
			}
		}
		s[index] = 1; //set the index of s equal to 1
		Project* ptr = table[index].head; //set a ptr equal to the head of the linkedlist
		while (ptr != NULL) {
			//if the project hasn't been added into the s array yet and the distance of index is less than ptr
			if (d[ptr->index] > d[index] + ptr->weight && s[ptr->index] == 0) {
				//this sets the smallest distance for ptr and pi
				d[ptr->index] = d[index] + ptr->weight;
				pi[ptr->index].projName = var.projName;
				heap->decreaseKey(ptr->projName, d[ptr->index]); //this decreases the d value for the node
			}
			ptr = ptr->next; //sets ptr equal to next element in the linkedlist
		}
	}

	//This loop locates the index of the finish node
	for (int i = 0; i < tableSize; i++) {
		if (table[i].name == finish) {
			index = i;
		}
	}
	//if the user command is length then print out the length
	if (check == "length") {

		//if the distance is equal to 10000 that means it was never processed/reached
		if (d[index] == 10000) {
			//throw an error if it was never reached
			cout << "Error: " << finish << " not reachable from " << start << endl;
		}
		//otherwise print the length
		else {
			cout << "LENGTH: " << d[index] << endl;
		}
	}
	//print the path
	else {
		//array arr will create an array of the path in reverse order
		string tempString = finish;
		string* arr = new string[tableSize];
		int count = 0;
		arr[0] = finish; //set first element in arr to the finish node
		bool checkPath = false; //this checks if the path is reachable
		//if the distance for the final node is 10000, then it was never reached
		if (d[index] == 10000) {
			cout << "Error: " << finish << " not reachable from " << start << endl;
		}
		//otherwise display the shortest path
		else {
			//loop continues until the start node is reached
			while (tempString != start) {
				//this locates the index of tempstring
				for (int i = 0; i < tableSize; i++) {
					if (table[i].name == tempString) {
						index = i;
					}
				}
				tempString = pi[index].projName; //sets tempstring equal to the project it was discovered from
				count++;
				arr[count] = tempString; //sets the next element in arr equal to next element in the path
			}

			//output the shortest path
			cout << "The shortest path:" << endl;
			for (int i = count; i >= 0; i--) {
				if (i == 0) {
					cout << arr[i] << endl;
				}
				else {
					cout << arr[i] << endl;
					cout << "->" << endl;
				}
			}
		}
	}
}