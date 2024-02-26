#include "1DArray.h"

// Câu 1 Nhập, xuất mảng 1 chiều n phần tử số nguyên
void inputArr(int a[], int& n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
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
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	cout << "\nXuat mang:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

// Câu 2 Tìm phần tử lớn nhất trong mảng 1 chiều.
int findMaxElement(int a[], int n) {
	int max = a[0];
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (max < a[i]) max = a[i];
	}

	cout << "So lon nhat trong mang la: " << max << endl;
	return max;
}

// Câu 3 Tính tổng các số không âm trong mảng 1 chiều.
int sumOfUnNegNum(int a[], int n) {
	int sum = 0;
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) sum += a[i];
	}

	cout << "Tong cac so khong am trong mang la: " << sum << endl;
	return sum;
}

// Câu 4 Tính tổng các phần tử tại vị trí chẵn trong mảng 1 chiều.
int sumOfEvenIndex(int a[], int n) {
	int sum = 0;
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) sum += a[i];
	}

	cout << "Tong cac so o vi tri chan: " << sum << endl;
	return sum;
}

// Câu 5 Đếm số lượng số nguyên tố trong mảng 1 chiều.
bool isPrime(int n) {
	bool prime = true;
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int countPrimeNum(int a[], int n) {
	int count = 0;
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) count++;
	}

	cout << "So cac so nguyen to trong mang la: " << count << endl;
	return count;
}

// Câu 6 Tìm phần tử âm lớn nhất trong mảng 1 chiều. Trả về phần tử đó.
int findNegMaxNum(int a[], int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	int max = -INT_MAX;
	bool found = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			max = a[i];
			found = 1;
			break;
		}
	}
	if (!found) {
		cout << "Khong tim thay so am nao trong mang!\n";
		return max;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0 && a[i] > max) {
			max = a[i];
		}
	}

	cout << "So am lon nhat la: " << max << endl;
	return max;
}

// Câu 7 Tìm phần tử không âm nhỏ nhất trong mảng 1 chiều. Trả về phần tử đó.
int findNoneNegMinNum(int a[], int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	int min = -INT_MAX;
	bool found = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			min = a[i];
			found = 1;
			break;
		}
	}

	if (!found) {

		cout << "Khong co phan tu khong am nao!\n";
		return min;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] < min && a[i] >= 0) {
			min = a[i];
		}
	}

	cout << "So khong am be nhat la: " << min << endl;
	return min;
}

// Câu 8 Kiểm tra mảng 1 chiều có tăng dần không.
void isIncrement(int a[], int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	bool isIn = true;
	for (int i = 0; i < n - 1; i++) {

		if (a[i] > a[i + 1]) {
			isIn = false;
			break;
		}
	}
	if (isIn) {
		cout << "Mang tang dan!" << endl;
	}
	else {
		cout << "Mang khong tang dan!" << endl;
	}
}

// Câu 9 Tính tổng các số chính phương trong mảng 1 chiều.
int sumSoChinhPhuong(int a[], int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sqrt(a[i]) * sqrt(a[i]) == a[i]) {
			sum += a[i];
		}
	}

	cout << "Tong cac so chinh phuong trong mang: " << sum << endl;
	return sum;
}