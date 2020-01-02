#include "Plane.h"

Plane::Plane(long long id, const std::string& plane, const std::string& type, long long flights) {
	setID(id);
	setPlane(plane);
	setType(type);
	setFlights(flights);
}

unsigned long long Plane::getID() const {
	return this->id;
}

void Plane::setID(unsigned long long id) {
	if (id < 0) {
		id *= -1;
		std::cout << "The ID you entered was invalid(a negative number. The record is saved with id*(-1)" << std::endl;
	}

	this->id = id;
}

void Plane::setType(const std::string& type) {
	if (type == "") {
		std::cout << "The type you entered was invalid so the record is saved with a default value TYPE" << std::endl;
		setType("TYPE");
	}

	this->type = type;
}

void Plane::setPlane(const std::string& plane) {
	if (plane == "") {
		std::cout << "The name you entered was invalid so the record is saved with a default value PLANE" << std::endl;
		setPlane("PLANE");
	}

	this->plane = plane;
}

void Plane::setFlights(unsigned long long flights) {
	if (flights < 0) {
		flights *= -1;
		std::cout << "The number of flights you entered was invalid(a negative number. The record is saved with flights*(-1)" << std::endl;
	}

	this->flights = flights;
}

std::ostream& operator<<(std::ostream& stream, const Plane& pl) {
	stream << pl.id << " " << pl.plane << " "
		<< pl.type << " " << pl.flights << "\n";

	return stream;
}

std::istream& operator>>(std::istream& stream, Plane& pl) {
	stream >> pl.id >> pl.plane >>
		pl.type >> pl.flights;

	return stream;
}

bool Plane::operator>(const Plane& pl) const {
	return this->id > pl.id;
}
