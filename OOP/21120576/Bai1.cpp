#include "vector.h"

int main() {

	vector<string> v(100);

	v.push("1");
	v.push("2");
	v.push("3");
	v.push("4");
	v.push("5");

	v.print();
	v.reserve(10);
	v.push("6");
	v.push("7");
	v.push("8");
	v.push("9");
	v.push("10");
	v.print();

	return 0;
}