//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
//Class Description: this fully implements the methods from the header file so that they
//			can be used in the Graph function 

#include <iostream>
#include <iomanip>
#include <string>
#include "MinHeap.h"

using namespace std;

//Essentially the constructor
void MinHeap::create(int n) {
	//creates the projectList and instantiates the size values
	projectList = new Object[n+1];
	currentSize = 0;
	minSize = n;
}

//Builds the MinHeap
void MinHeap::buildMinHeap(Object * otherList, int sizeOfOtherList) {

	//For loop that copies otherList into projectList
	for (int i = 1; i <= sizeOfOtherList; i++) {
		//Put cost and projName of otherList into each index of projectList
		projectList[i].cost = otherList[i].cost;
		projectList[i].projName = otherList[i].projName;
	}

	//For loop goes through heap and recursively performs heapify
	for (int i = currentSize / 2; i >= 1; i--) {
		heapify(i);
	}
}

//Seperate method to build MinHeap without having to pass a linkedList
void MinHeap::buildMin(int currentSize) {
	//For loop goes through heap and recursively performs heapify
	for (int i = currentSize / 2; i >= 1; i--) {
		heapify(i);
	}
}

//This method turns a heap into a MinHeap
void MinHeap::heapify(int i) {

	int left = 2 * i;	//Initialize left to left child index of parent
	int right = (2 * i) + 1;	//Initialize right to right child index of parent
	int smallest = 0;	//Initialize smallest to zero
	int len = currentSize;	//Set len equal to the size of projectList

	//Initialize an int and string that can be used for swap 
	int cost2 = 0;
	string name2 = "";

	//If left child is in the heap and left cost is smaller than parent then, left becomes smallest
	if (left <= len && projectList[left].cost < projectList[i].cost) {
		smallest = left;
	}
	else {
		smallest = i;
	}
	//If right child is in the heap and right key is smaller than either left or parent. Smallest becomes equal to right
	if (right <= len && projectList[right].cost < projectList[smallest].cost) {
		smallest = right;
	}
	//Performs a swap with child and parent node if a child is smaller than parent
	if (smallest != i) {
		cost2 = projectList[i].cost;
		name2 = projectList[i].projName;

		projectList[i].cost = projectList[smallest].cost;
		projectList[i].projName = projectList[smallest].projName;
		projectList[smallest].cost = cost2;
		projectList[smallest].projName = name2;

		heapify(smallest);	//Recursively keep performing heapify
	}
}

//This removes the smallest node from the heap and returns the smallest node
Object MinHeap::extractMin() {
	Object min = projectList[1]; //Sets min equal to the cost of the min node
	//Removes the min node by setting it equal to the largest node
	projectList[1].cost = projectList[currentSize].cost;
	projectList[1].projName = projectList[currentSize].projName;
	currentSize--;	//Lowers the size of the heap by 1	
	buildMinHeap(projectList, currentSize);	//Creates the min heap after the removal of the max node
	return min;	//returns the value of the previous min cost
}

//Lowers the cost of a specific chosen node
void MinHeap::decreaseKey(string name, int newCost) {
	int tempCost = 0;
	string tempName = "";
	int index = -1;
	//For loop goes through projNames to find the index
	for (int i = 0; i < currentSize; i++) {
		if (projectList[i].projName == name) {
			index = i;
		}
	}
	projectList[index].cost = newCost;	//Sets the nodes cost to new cost
	//The while loop continues to run as long as the child node is smaller than the parent node
	while (index > 1 && projectList[index / 2].cost > projectList[index].cost) {
		//Sets temporary variables equal to child node values
		tempCost = projectList[index].cost;
		tempName = projectList[index].projName;

		//Swaps both the parent and child nodes
		projectList[index].cost = projectList[index / 2].cost;
		projectList[index].projName = projectList[index / 2].projName;
		projectList[index / 2].cost = tempCost;
		projectList[index / 2].projName = tempName;

		index = index / 2;	//Changes the index of the child node to the parent
	}
}

//inserts a new node into the heap
void MinHeap::minHeapInsert(string name, int weight) {
	currentSize++;	//Increment currentSize by one so that memory can be allocated for the new node
	//Set the new node equal to newProjectName and newCost
	projectList[currentSize].cost = weight;
	projectList[currentSize].projName = name;

	//With the new node build the max Heap
	buildMinHeap(projectList, currentSize);
}

//checks whether the heap is true or false
bool MinHeap::checkEmpty() {
	if (currentSize == 0) {
		return true;
	}
	else {
		return false;
	}
}