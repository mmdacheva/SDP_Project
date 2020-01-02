#include "PlanesDataBase.h"

unsigned int PlanesDataBase::countOfLines() {
	unsigned int count = 0;
	std::ifstream iFile("Planes.txt");
	if (!iFile)
		std::cerr << "Couldn't open file!" << std::endl;

	while (!iFile.eof()) {
		iFile.ignore(sizeof(Plane) * 4, '\n');
		count++;
	}

	iFile.close();
	return count - 1;
}

PlanesDataBase::PlanesDataBase(const std::string& fileName) : isOptimized(false) {
	this->fileName = fileName;
	readFromFile();
}

void PlanesDataBase::search(unsigned long long id) {
	if(isOptimized) {
		optimizedSearch(id);
		return;
	}

	int index = searchByID(id);
	if (index == -1) {
		std::cout << "Plane with that ID doesn't exist!" << std::endl;
		return;
	}

	std::cout << planesData[index];
}

int PlanesDataBase::searchByID(unsigned long long id) const {
	for (int i = 0; i < planesData.size(); i++) {
		if (planesData[i].getID() == id) return i;
	}

	return -1;
}

void PlanesDataBase::changeAttribute(unsigned long long id, const std::string& attribute, const std::string& update) {
	int index = searchByID(id);
	if (index == -1){
		std::cout << "Plane with that ID does not exist!" << std::endl;
		return;
	}
	
	if (attribute == "Id")
		planesData[index].setID(stoi(update));
	else if (attribute == "Plane")
		planesData[index].setPlane(update);
	else if (attribute == "Type")
		planesData[index].setType(update);
	else if (attribute == "Flights")
		planesData[index].setFlights(stoi(update));

	removeOptimized();
}

void PlanesDataBase::optimize() {
	isOptimized = true;

	for (int i = 0; i < planesData.size(); i++) {
		planesDataOptimized.insert(planesData[i]);
	}
}

void PlanesDataBase::show(unsigned int offset, unsigned int limit) const {
	if (offset < 0 || offset >= planesData.size()) {
		std::cout << "Invalid argument offset" << std::endl;
		return;
	}

	if (offset + limit > planesData.size()) {
		std::cout << "Invalid arguments. The data base doesn't have so many records" << std::endl;
		return;
	}

	for (int i = offset; i < offset + limit; i++) {
		std::cout << planesData[i];
	}
}

void PlanesDataBase::addPlane(long long id, const std::string& plane, const std::string& type, long long flights) {
	if (searchByID(id) != -1) {
		std::cout << "Plane with this ID already exists. ID must be unique" << std::endl;
		return;
	}

	Plane pl(id, plane, type, flights);
	planesData.push_back(pl);

	if(isOptimized) removeOptimized();
}

void PlanesDataBase::deletePlane(unsigned long long id) {
	unsigned long long index = searchByID(id);

	if (index == -1) {
		std::cout << "Plane with this ID doesn't exist" << std::endl;
		return;
	}

	planesData.erase(planesData.begin() + index);
	removeOptimized();
}

void PlanesDataBase::readFromFile() {
	std::ifstream iFile(fileName);
	if (!iFile) 
		std::cerr << "Couldn't open file!" << std::endl;
	
	unsigned int countPlanes = countOfLines();
	if (countPlanes) {
	
		for (int i = 0; i < countPlanes; i++) {
			Plane pl;
			iFile >> pl;
			planesData.push_back(pl);
		}
	}

	else
		std::cout << "File is empty!" << std::endl;

	iFile.close();
}

void PlanesDataBase::optimizedSearch(unsigned long long id) {
	std::cout << planesDataOptimized.search(id);
}

void PlanesDataBase::removeOptimized() {
	if (isOptimized) {
		isOptimized = false;
		planesDataOptimized.clear();
		planesDataOptimized.reset();
	}
}

void PlanesDataBase::writeToFile() {
	std::ofstream oFile(fileName);
	if (!oFile)
		std::cerr << "Coundl't open file!" << std::endl;
	
	for (int i = 0; i < planesData.size(); i++) {
		oFile << planesData[i];
	}

	oFile.close();

	if (isOptimized) {
		isOptimized = false;
		planesDataOptimized.clear();
	}
}