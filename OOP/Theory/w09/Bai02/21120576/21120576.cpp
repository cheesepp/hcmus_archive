#include "MyException.h"
#include "AgeInput.h"

int main() {

	int low, high;
	cout << "Enter lower bound: ";
	cin >> low;
	cout << "Enter upper bound: ";
	cin >> high;
	AgeInput ageBound(low, high);

	while (1) {
		try {
			
			int age = ageBound.getAge();
			cout << "Your age: " << age << endl;
			break;

		}
		catch (myException e) {
			cout << e.getMessage() << endl;
			continue;
		}
	}


	return 0;
}