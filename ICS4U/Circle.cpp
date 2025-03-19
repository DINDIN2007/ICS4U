#include <iostream>
#include "Circle.h"


Circle::Circle(std::string n, double r) : Shape(n) 
{radius = r;}

void Circle::setRadius(double r)
{radius = r;}

double Circle::getRadius() const
{return radius;}

double Circle::getArea() const
{return 3.14159 * radius * radius;}