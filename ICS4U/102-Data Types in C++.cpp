#include <iostream>
#include <string>

int main_102() {
	// a) variable to store the number of students in this school
	int numOfStudents{ 1000 };
	std::cout << "There are " << numOfStudents << " students";

	// b) constant to store the mass of Jupiter
	const double massOfJupiter{ 1.898e27 };
	std::cout << "The mass of Jupiter is " << massOfJupiter;

	// c) variable store your first initial
	char firstInitial{ 'D' };
	std::cout << "My first initial is " << firstInitial;

	// d) variable to store your answer to a true / false question
	bool isAnswerTrue{};
	std::cout << "The answer to the question is " << isAnswerTrue << ".\n";

	// e) variable to store a person's age
	int age{};
	std::cout << "This person is " << age << " years old.";

	// f) variable to store the population of a country
	int population{};

	// g) variable to store your name
	std::string name = "Dinh";

	return 0;
}