#include <iostream>
#include "Triangle.h"

Triangle::Triangle(std::string n, double b, double h) : Shape(n)
{base = b; height = h;}

void Triangle::setBase(double b)
{base = b;}

double Triangle::getBase() const
{return base;}

void Triangle::setHeight(double h)
{height = h;}

double Triangle::getHeight() const
{return height;}

double Triangle::getArea() const
{return 0.5 * base * height;}