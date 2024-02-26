#include "1DArray.h"

void inputI2DArr(int a[][MAX], int& m, int& n) {
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void outputI2DArr(int a[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void findMinMax(int a[][MAX], int m, int n) {
	int max = a[0][0];
	int min = a[0][0];
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (max < a[i][j]) {
				max = a[i][j];
			}
			if (min > a[i][j]) {
				min = a[i][j];
			}
		}
	}
	cout << "So lon nhat trong mang: " << max << endl;
	cout << "So be nhat trong mang: " << min << endl;
}

void inputF2DArr(float ar[][MAX], int& m, int& n) {
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> ar[i][j];
		}
	}
}

void outputF2DArr(float a[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void sort2DArr(float a[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int h = 0; h < m; h++) {
				for (int k = 0; k < n; k++) {
					if (a[i][j] < a[h][k]) {
						swap(a[i][j], a[h][k]);
					}
				}
			}
		}
	}
}

void sort2DArrWExArr(float arr[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	float sorted_arr[MAX][MAX];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sorted_arr[i][j] = arr[i][j];
		}
	}

	sort2DArr(sorted_arr, m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = sorted_arr[i][j];
		}
	}
}

void findHorseSaddle(int a[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	cout << "Cac diem yen ngua tim thay: " << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			bool isSaddle = true;
			for (int h = 0; h < m; h++) {
				if (h == i) continue;
				if (a[i][j] < a[h][j]) {
					isSaddle = false;
					break;
				}
			}
			for (int k = 0; k < n; k++) {
				if (k == j) continue;
				if (a[i][j] > a[i][k]) {
					isSaddle = false;
					break;
				}
			}
		if (isSaddle) {
			cout << "Dong " << i << " cot " << j << endl;
		}
		}
	}
}

void create2DArr(int a[][MAX], int m, int n, int b[][MAX]) {
	int hi = 0;
	int kj = 0;
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int countPos = 0;
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; y <= j + 1; y++) {
					if (x < 0 || x == m) continue;
					if (y < 0 || y == n) continue;
					if (x == i && y == j) continue;
					if (a[x][y] > 0) {
						countPos++;
					}
				}
			}
			while (hi < m) {
				if (kj < n) {
					b[hi][kj] = countPos;
					kj++;
					break;
				}
				kj = 0;
				hi++;
				
			}
		}
	}
}

void sortBySumRow(int a[][MAX], int m, int n) {
	if (n == 0) {
		cout << "Ma tran rong!\n";
		return;
	}
	int i;
	int h;
	for (i = 0; i < m; i++) {
		int sumCurr = 0;
		for (int j = 0; j < n; j++) {
			sumCurr += a[i][j];
		}
		for (h = i + 1; h < m; h++) {
			int sumNext = 0;
			for (int k = 0; k < n; k++) {
				sumNext += a[h][k];
			}
			if (sumCurr > sumNext) {
				for (int j = 0; j < n; j++) {
					swap(a[i][j], a[h][j]);
				}
			}
		}
	}
}


