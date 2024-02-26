#include "Stack.h"
#include "Windows.h"

int main() {

	int n;
	cin >> n;
	Stack s;
	for (int i = 0; i < n; i++) {

		try {
			int random = rand() % 15 + 1;
			Sleep(1000);

			s.push(random);
		}
		catch (string e) {
			cout << e;
		}
	}
	s.print();
	
}