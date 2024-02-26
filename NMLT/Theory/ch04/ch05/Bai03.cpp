#include <iostream>
#include <cstring>
using namespace std;

int main() {

	int num;
	int i = 1;
	cout << "Number " << i << ": ";
	int max = 0;
	int min = 0;
	bool isDirty = false;
	while (cin >> num) {
		if (!isDirty) {
			max = num;
			min = num;
			isDirty = true;
			i++;
			cout << "number " << i << ": ";
			continue;
		}
		if (max < num) max = (num);
		if (min > num) min = (num);
		i++;
		cout << "number " << i << ": ";
	}
	cout << "gia tri lon nhat: " << max << endl;
	cout << "gia tri be nhat: " << min << endl;
	return 0;
}