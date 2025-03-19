#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(std::string n, double w, double l) : Shape(n)
{width = w; length = l;}

void Rectangle::setWidth(double w)
{width = w;}

double Rectangle::getWidth() const
{return width;}

void Rectangle::setLength(double l)
{length = l;}

double Rectangle::getLength() const
{return length;}

double Rectangle::getArea() const
{return width * length;}