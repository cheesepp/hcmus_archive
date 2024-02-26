#include <iostream>
#define MAX 100
using namespace std;

void inputArr(int a[], int& n) {
	cout << "Nhap so luong phan tu: ";
	do {
		cin >> n;
		if (n <= 0 || n > MAX) {
			cout << "Phai lon hon khong va be hon " << MAX << "!\n";
		}
	} while (n <= 0 || n > MAX);

	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void outputArr(int a[], int n) {
	cout << "\nXuat mang:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

bool isEven(int a[], int n) {
	bool even = false;
	for (int i = 0; i < n; i++) {

		if (a[i] % 2 == 0) {
			even = true;
		}
		else {
			even = false;
			break;
		}
	}
	return even;
}

bool isPrime(int n) {
	bool prime = true;
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i != 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

bool isAllPrime(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (!isPrime(a[i])) return false;
	}
	return true;
}

bool isIncrement(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {

		if (a[i] < a[i + 1]) return false;
	}
	return true;
}

void eleDivisibleBy3and5(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 0 && a[i] % 5 == 0) {
			cout << a[i] << " ";
		}
	}
}

int sumArr(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) sum += a[i];
	}

	return sum;
}

int sumOddElements(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) sum += a[i];
	}

	return sum;
}

int sumEvenElements(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) sum += a[i];
	}

	return sum;
}

int findFirst(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) return i;
	}
}

int findLast(int a[], int n, int x) {
	int lastIndex = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) lastIndex = i;
	}
	return lastIndex;
}

void findSmallestAndLargestValue(int a[], int n) {
	int min = a[0];
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}
	cout << "Gia tri nho nhat: " << min << endl;
	cout << "Gia tri lon nhat: " << max << endl;
}


void findSmallestPositiveValue(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i] && a[i] > 0) min = a[i];
	}
	cout << "Gia tri duong nho nhat: " << min << endl;
}

void initArr(int a[], int n) {
	
	for (int i = 0; i < n; i++) {
		a[i] = 0;
	}
}

void segregatesArr(int a[], int b[], int c[], int n) {
	int t1 = 0;
	int t2 = 0;
	initArr(b, n);
	initArr(c, n);
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] = b[t1++];
		}
		else {
			a[i] = c[t2++];
		}
	}
}

void appendPrime(int b[], int c[], int r[], int m, int l, int& o) {

	int i = 0;
	int j = 0;
	int d = 0;
	o = m + l;
	while (i < m && j < l) {
		if (isPrime(b[i])) r[d++] = b[i];
		if (isPrime(c[j])) r[d++] = c[j];
		i++;
		j++;
	}

	while (i < m) {
		if (isPrime(b[i])) r[d++] = b[i];
	}
	
	while (j < l) {
		if (isPrime(c[j])) r[d++] = c[j];
	}
}

void replacePrimeW0(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) a[i] = 0;
	}
}

void removePrime(int a[], int n) {
	for (int i = 0; i < n; i++) {

		if (isPrime(a[i])) {
			for (int j = i; j < n- 1; j++) {
				a[j] = a[j + 1];
			}
			n--;
		}
	}
}

void insert0BefPrime(int a[], int out[], int n) {
	out[MAX];
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			out[j++] = 0;
		}
		out[j++] = a[i];
	}

}

void sortArrAscenOrder(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void sortArrPosDesnNegAs(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}

	int posIndex = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) posIndex = i;
	}

	for (int i = posIndex; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}



int main() {


	return 0;
}