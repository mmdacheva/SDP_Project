#pragma once
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Plane.h"

class PlanesDataBase {
	std::vector<Plane> planesData;
	BST planesDataOptimized;
	std::string fileName;
	bool isOptimized;
	std::stack<std::string> commands;
	std::stack<Plane> planeStack;
	std::stack<int> affectedID;

	unsigned int countOfLines();
	void readFromFile();
	void optimizedSearch(unsigned long long id);
	void removeOptimized();
	int searchByID(unsigned long long id) const;


public:
	PlanesDataBase(const std::string& fileName);

	void search(unsigned long long id);
	void changeAttribute(unsigned long long id, const std::string& attribute, const std::string& update);
	void optimize();
	void show(unsigned int offset, unsigned int limit);
	void addPlane(long long id, const std::string& plane, const std::string& type, long long flights);
	void deletePlane(unsigned long long id);
	void undoCommand();

	void writeToFile();
};
