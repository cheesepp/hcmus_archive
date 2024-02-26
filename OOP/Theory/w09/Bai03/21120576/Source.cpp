#include "Divide.h"

int main() {

	Divide div;
	div.input();

	try {
		double result = div.division();
		cout << "Ket qua: " << result << endl;
	}
	catch (myException e) {
		cout << e.getMessage() << endl;
	}

	return 0;
}