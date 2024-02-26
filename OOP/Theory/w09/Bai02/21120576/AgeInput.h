#pragma once
#ifndef AGEINPUT_H
#define AGEINPUT_H
#include "MyException.h"
class AgeInput : public myException {
private:

	string DEFAULT_MESSAGE = "Your age must be in lower bound and upper bound! ";
	int DEFAULT_LOWER_BOUND = 0;
	int DEFAULT_UPPER_BOUND = 99;
	int lowerBound;
	int upperBound;

public:
	// Constructors
	AgeInput();
	AgeInput(int low, int high);
	int getAge();
	// Method: enter age and checking entrace data bound
	int getAge(string promt);
};

#endif // !AGEINPUT_H


