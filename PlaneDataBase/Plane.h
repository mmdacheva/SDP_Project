#pragma once
#include <iostream>
#include <string>
class Plane {
	unsigned long long id;
	std::string plane;
	std::string type;
	unsigned long long flights;

public:
	Plane() {}
	Plane(unsigned long long id, const std::string& plane, const std::string& type, unsigned long long flights);

	unsigned long long getID() const;

	void setID(unsigned long long id);
	void setType(const std::string& type);
	void setPlane(const std::string& plane);
	void setFlights(unsigned long long flights);

	bool operator >(const Plane& pl) const;

	friend std::ostream& operator<<(std::ostream& stream, const Plane& pl);
	friend std::istream& operator>>(std::istream& stream, Plane& pl);
	};

