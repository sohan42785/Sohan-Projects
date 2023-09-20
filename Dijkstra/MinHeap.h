//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
//Class Description: This declares all the methods so they can be implemented in the MinHeap.cpp file

#pragma once

#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
using namespace std;

// struct Object
struct Object {
	int cost;
	string projName;
};

// create a MinHeap
struct MinHeap {
	int minSize;
	int currentSize;
	struct Object * projectList;

	void create(int);
	void buildMinHeap(Object * otherList, int sizeOfOtherList);
	void buildMin(int);
	void heapify(int);
	Object extractMin();
	void minHeapInsert(string, int);
	void decreaseKey(string, int);
	bool checkEmpty();
};

#endif 
