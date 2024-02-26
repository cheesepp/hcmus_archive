#include "Function.h"

void inputArr1(int a[], int& n)
{
	do {
		cout << "Nhap so luong phan tu (so luong lon hon 9 va la so chinh phuong): ";
		cin >> n;
		
	} while (n < 9 || sqrt(n) != (int)(sqrt(n)));

	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void outputArr1(int a[], int n)
{
	cout << "\nXuat mang:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void primeArr2(int a2[], int a1[], int n, int &a2Index)
{
	for (int i = 0; i < n; i++) {
		if (isPrime(a1[i])) {
			a2[a2Index++] = a1[i];
		}
	}
}

void createMatrix(int a[][MAX], int a1[], int n, int &m)
{
	m = sqrt(n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = a1[j + m * i];
		}
	}
}

void outputMatrix(int a[][MAX], int n)
{
	cout << "\n------ Xuat matrix -------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int tichPhanTu2Bien(int a[][MAX], int m)
{
	int result = 1;
	for (int i = 0; i < m; i++) {	
		for (int j = 0; j < m; j++) {
			if (j == 0 || j == m - 1) {
				result *= a[i][j];
			}
		}
	}
	return result;
}


