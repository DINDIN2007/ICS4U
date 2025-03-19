#include <iostream>
#include "Shape.h"

Shape::Shape(std::string s) 
{name = s;}

void Shape::setName(std::string s) 
{name = s;}

std::string Shape::getName() const
{return name;}