//Sohan Byrapuneni
//sbyrapun@asu.edu
//Assignment 7
// Class Description: This is the main function, user inputs are processed here

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;

int main() {
	int projCount, firstSpace,edgeCount, distance, secondSpace, thirdSpace, fourthSpace;
	string command, input, commandEnd, projectName, start, end, shortestCommand, firstLength, lastLength, nextLength;

	Graph* list1 = new Graph();	//Declared so the Graph methods can be used
	//Gets user input and set command equal to everything before the first space
	getline(cin,input);
	firstSpace = input.find(' ', 0);
	command = input.substr(0, firstSpace);
	cout << "Next Command: " << input << endl;
	while (true) {
		if (command == "fileread") {
			//Reads the file using the data creates all the nodes
			ifstream file1;
			file1.open("graphInfo.txt");
			file1 >> projCount;
			file1 >> edgeCount;
			list1 = new Graph(projCount);
			//Creates a table index for each project
			for (int i = 0; i < projCount; i++) {
				file1 >> projectName;
				list1->addNode(projectName, i);
			}
			// Creates the linked list for each of the nodes from start to end
			for (int i = 0; i < edgeCount; i++) {
				file1 >> start;
				file1 >> end;
				file1 >> distance;
				list1->addEdge(start, end, distance);
			}
			file1.close();
			//Get the next command
			getline(cin, input);
			firstSpace = input.find(' ', 0);
			command = input.substr(0, firstSpace);
			cout << "Next Command: " << input << endl;
		}
		else if (command == "print") {
			list1->checkGraph(); //I graph is not initialized throw an error if it is then print the Graph Contents
			//Get the next command
			getline(cin, input);
			firstSpace = input.find(' ', 0);
			command = input.substr(0, firstSpace);
			cout << "Next Command: " << input << endl;
		}
		else if (command == "shortest") {
			//From the user input cut it into both projNames and specific command ("path", "length", or other)
			projCount = input.length();
			shortestCommand = input.substr(projCount-4);
			secondSpace = input.find(' ', 9);
			thirdSpace = input.find(' ', secondSpace+1);
			fourthSpace = input.find(' ', thirdSpace+1);
			nextLength = input.substr(firstSpace+1, secondSpace-firstSpace-1);
			firstLength = input.substr(secondSpace+1, thirdSpace-secondSpace-1);
			lastLength = input.substr(thirdSpace+1, fourthSpace-thirdSpace-1);
			//if user wants "length" or "path" then get those methods otherwise output an error
			if (lastLength == "length" || lastLength == "path") {
				//Runs length method with start and finish project, if there are no errors, otherwise it displays an error
				list1->checkLength(nextLength, firstLength, lastLength);
			}
			else {
				//Outputs an error, but has to select the correct error, with the passing of the start and finish nodes
				list1->checkInvalid(nextLength, firstLength);
			}
			//Get the next command
			getline(cin, input);
			firstSpace = input.find(' ', 0);
			command = input.substr(0, firstSpace);
			cout << "Next Command: " << input << endl;
		}
		else if (command == "quit") {
			break;
		}
		else {
			break;
		}
	}
}