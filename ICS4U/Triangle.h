#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include "Shape.h"

// third child class
class Triangle : public Shape {
	double base, height;

public:
	Triangle(std::string n, double b, double h);
	
	void setBase(double b);

	double getBase() const;

	void setHeight(double h);

	double getHeight() const;

	virtual double getArea() const;
};

#endif