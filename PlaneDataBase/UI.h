#pragma once
#include "PlanesDataBase.h"

//creates record for a plane with this data
static void create(PlanesDataBase& db, long long id, std::string plane,
	std::string type, long long flights) {
	db.addPlane(id, plane, type, flights);
}

//deletes by ID
static void deleteById(PlanesDataBase& db, unsigned int id) {
	db.deletePlane(id);
}

//updates ID or Plane or Type or Flights
static void update(PlanesDataBase& db, unsigned long long id, const std::string& attribute, const std::string& newInfo) {
	db.changeAttribute(id, attribute, newInfo);
}

//prints limit number of full records beginning from offset
static void show(PlanesDataBase& db, unsigned int offset, unsigned int limit) {
	db.show(offset, limit);
}

//creates binary ordered tree by id
static void optimize(PlanesDataBase& db) {
	db.optimize();
}

//prints plane with id
static void search(PlanesDataBase& db, unsigned int id) {
	db.search(id);
}

static void getInput() {
	PlanesDataBase db("Planes.txt");
	std::string input;

	while (true) {
		std::cin >> input;

		if (input == "create") {
			unsigned long long id;
			std::string plane;
			std::string type;
			unsigned long long flights;

			std::cin >> id >> plane >> type >> flights;
			
			create(db, id, plane, type, flights);
		}

		else if (input == "update") {
			int id;
			std::string attribute;
			std::string newInfo;
			std::cin >> id >> attribute >> newInfo;

			update(db, id, attribute, newInfo);
		}

		else if (input == "delete") {
			int id; std::cin >> id;

			deleteById(db, id);
		}

		else if (input == "show") {
			int offset, limit;
			std::cin >> offset >> limit;

			show(db, offset, limit);
		}

		else if (input == "optimize") {
			optimize(db);
		}

		else if (input == "search") {
			int id; std::cin >> id;

			search(db, id);
		}

		else if (input == "exit") {
			db.writeToFile();
			break;
		}

		else
			std::cout << "Invalid command" << std::endl;

	}
		
}