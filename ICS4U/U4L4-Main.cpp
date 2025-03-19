#include <iostream>
#include <string>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
	Circle c("Circle", 3);
	c.setName("Circle, too");
	std::cout << c.getName() << " " << c.getRadius() << std::endl;
	std::cout << c.getArea() << std::endl;

	Rectangle r("Rectangle", 3, 4);
	r.setWidth(10);
	std::cout << r.getName() << " " << r.getWidth() << " " << r.getLength() << std::endl;
	std::cout << r.getArea() << std::endl;

	Triangle t("Triangle", 4, 3);
	t.setBase(10);
	std::cout << t.getName() << " " << t.getBase() << " " << t.getHeight() << std::endl;
	std::cout << t.getArea() << std::endl << std::endl;

	Shape* shape[3] = {
		new Circle("Circle", 2.1),
		new Rectangle("Rectangle", 3.1, 4.1),
		new Triangle("Triangle", 4.1, 5.1)
	};

	for (int i = 0; i < 3; i++) {
		std::cout << shape[i]->getName() << " " << shape[i]->getArea() << "\n";
	}

	return 0;
}