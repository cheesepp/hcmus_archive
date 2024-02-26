#include "AgeInput.h"

AgeInput::AgeInput()
{
	int loweerBound = 0;
	int upperBound = 99;
}

AgeInput::AgeInput(int low, int high)
{
	lowerBound = low;
	upperBound = high;
}

int AgeInput::getAge()
{
	return getAge(DEFAULT_MESSAGE);
}

int AgeInput::getAge(string promt)
{
	cout << "Enter your age: ";
	int age;
	cin >> age;
	if (age < lowerBound || age > upperBound) {
		throw myException(promt);
	}
	return age;
}
