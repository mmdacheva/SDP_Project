#pragma once
#include <vector>
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

	unsigned int countOfLines();
	void readFromFile();
	void optimizedSearch(unsigned long long id);
	void removeOptimized();

	int searchByID(unsigned long long id) const;

public:
	PlanesDataBase(const std::string& fileName);

	void search(unsigned long long id);
	void changeAttribute(unsigned long long index, const std::string& attribute, const std::string& update);
	void optimize();
	void show(unsigned int offset, unsigned int limit) const;
	void addPlane(unsigned long long id, const std::string& plane, const std::string& type, unsigned long long flights);
	void deletePlane(unsigned long long id);

	void writeToFile();
};