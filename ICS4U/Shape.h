#ifndef SHAPE_H_
#define SHAPE_H_

// Abstract base class
class Shape {
protected:
	std::string name;

public:
	Shape(std::string s);

	void setName(std::string s);

	std::string getName() const;

	// pure virtual function
	virtual double getArea() const = 0;
};

#endif