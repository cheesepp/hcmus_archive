#include "Student.h"

int main() {

	Student std1(100000001, 2);
	Student std2(std1);
	Student std3 = std1;
	std3.print();
	Student std4;
	std4.input();
	Student std5 = std4;
	std5.print();
	return 0;
}