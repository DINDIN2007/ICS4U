#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"
#include <iostream>

// first child class
class Circle : public Shape {
	double radius;

public:
	Circle(std::string n, double r);

	void setRadius(double r);

	double getRadius() const;

	virtual double getArea() const;
};

#endif