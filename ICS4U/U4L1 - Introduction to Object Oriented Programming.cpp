#include <iostream>
#include <windows.h>
#include <iomanip>
#include <ctime>
#include <string>

//ASSIGNMENT DETAIL
/*Design and create a simple class to model an object of your choice.
The example in the second video should be helpful.
Try to choose an object that has 2 different attributes and 2 different actions.
Make 2 instances of the class and test to make sure it is working.
Submit your work to Google Classroom when finished.*/

// Record Struct to contain the time saved in the watch
struct Time {
	int hour, min, sec;
};

class DigitalWatch {
	public:
		// Variables for the Watch
		Time time, stopWatchTime;
		bool is24HourClock = false;
		int colorSelection = 0;

		// Class Functions
		void changeMode() {is24HourClock = !is24HourClock;}
		void getTime();
		void changeColor(int selection);
};

// Reference : 
// https://cplusplus.com/reference/ctime/time/
void DigitalWatch::getTime() {
	// Get the current time as a time_t object
	std::time_t currentTime = std::time(nullptr);

	// Convert the time to local time (struct tm)
	std::tm localTime;
	localtime_s(&localTime, &currentTime);

	// Store hour, minute, and second in separate variables
	time.hour = localTime.tm_hour;
	time.min = localTime.tm_min;
	time.sec = localTime.tm_sec;
}

void printTime(DigitalWatch watch) {
	// Get the current time
	watch.getTime();

	// Find the struct Time of the watch
	Time time = watch.time;

	// Print the time, accounting for 12-hour or 24-hour clock format
	if (watch.is24HourClock) {
		std::cout << std::setfill('0') << std::setw(2) << time.hour;
	}
	else {
		int displayHour = (time.hour == 0) ? 12 : (time.hour > 12) ? time.hour - 12 : time.hour;
		std::cout << std::setfill('0') << std::setw(2) << displayHour;
	}

	// Print Minutes
	std::cout << ":";
	std::cout << std::setfill('0') << std::setw(2) << time.min;
	
	// Print Seconds
	std::cout << ":";
	std::cout << std::setfill('0') << std::setw(2) << time.sec;

	// Print AM/PM suffixes if necessary
	if (!watch.is24HourClock) {
		std::cout << (time.hour < 12 ? " AM" : " PM");
	}
	std::cout << std::endl;

}

void DigitalWatch::changeColor(int selection) {
	// Chooses a theme for the alarm clock UI based on user selection (1 - 8)
	switch (selection) {
		case 1:
			system("Color 70"); // White background, Black text
			break;
		case 2:
			system("Color 8F"); // Gray background, white text
			break;
		case 3:
			system("Color 17"); // Dark Blue background, Gray text
			break;
		case 4:
			system("Color A0"); // Light Green background, black text
			break;
		case 5:
			system("Color B0"); // Light Blue background, black text
			break;
		case 6:
			system("Color C0"); // Light Red background, black text
			break;
		case 7:
			system("Color D0"); // Light Magenta background, black text
			break;
		case 8:
			system("Color E0"); // Yellow background, black text
			break;
		// Cool watch fun
		case 100:
			system("Color 1E");
			break;
		default:
			system("Color 07");	// Default black background, white text
	}
}

int main() {
	// Declare a watch from the Digital watch class
	DigitalWatch watch, coolWatch;

	// Run this segment until 
	bool isProgramEnded = false, isCoolWatch = false;
	while (!isProgramEnded) {
		// Ask the user to select one of the options to run the watche's functions
		std::cout << "Choose what to do next with this watch\nOPTIONS :";
		if (!isCoolWatch) std::cout << "\"Switch to COOL Watch\" | ";
		std::cout << "\"See Time\" | ";
		// A cool watch does not need to change themes, it's perfecto
		if (!isCoolWatch) std::cout << "\"Change Theme\" | ";
		// Choose which text to display for the switch between AM/PM to 24 hour clock
		bool is24HourClock = watch.is24HourClock;
		if (isCoolWatch) is24HourClock = coolWatch.is24HourClock;
		if (is24HourClock) std::cout << "\"Switch to AM/PM\"";
		else std::cout << "\"Switch to 24 hour clock\"";
		// End program option
		std::cout << " | \"End Program\"\n\n";

		// Ask which function to run
		std::string command;
		std::cout << "Enter selection : ";
		std::getline(std::cin, command);
		std::cout << "\n";

		// Run the selected function
		if (command == "Switch to COOL Watch") {
			isCoolWatch = true;
			coolWatch.changeColor(100);
		}
		else if (command == "See Time") {
			if (isCoolWatch) printTime(coolWatch);
			else printTime(watch);
		}
		else if (command == "Change Theme" && !isCoolWatch) {
			std::cout << "Choose a theme from 1 to 9 : ";
			int theme; std::cin >> theme;
			watch.changeColor(theme);
			std::getline(std::cin, command); // To fix weird bug where asking for int and string is interchanged
		}
		else if (command[0] == 'S') { // For the 24 hour to AM/PM Switches
			if (isCoolWatch) coolWatch.changeMode();
			else watch.changeMode();
			std::cout << "Mode Switched\n";
		}
		else if (command == "End Program") {
			isProgramEnded = true;
		}
		else {
			std::cout << "Invalid Input\n";
		}
		std::cout << "\n---------------------------------------\n\n";
	}

	// End of program
	std::cout << "Program Ended";
	return 0;
}