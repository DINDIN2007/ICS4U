#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include "Shape.h"

// second child class
class Rectangle : public Shape {
	double width, length;

public:
	Rectangle(std::string n, double w, double l);

	void setWidth(double w);

	double getWidth() const;

	void setLength(double l);

	double getLength() const;

	virtual double getArea() const;
};

#endif