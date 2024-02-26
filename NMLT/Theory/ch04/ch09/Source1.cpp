#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;
};

bool writeListPoint(const char* filename, Point a[], int n) {
	FILE* fp = fopen(filename, "w");
	if (!fp) {
		cout << "Chua mo duoc file!";
		return 0;
	}
	fprintf(fp, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d %d\n", a[i].x, a[i].y);
	}
	fclose(fp);
}

bool readListPoint(const char* filename, Point a[], int& n) {
	
	FILE* fp = fopen(filename, "r");

	if (!fp) {
		cout << "Chua mo duoc file!";
		return 0;
	}

	fscanf(fp, "%d \n", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d %d", &a[i].x, &a[i].y);
		cout << a[i].x << " " << a[i].y << endl;
	}
	
	fclose(fp);
	return 1;
}

bool findMostDistance(const char* filename, Point a[], int n) {
	Point b, c;
	double distanceMax = -INT_MAX * 1.0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double distance = sqrt(pow(a[j].x - a[i].x, 2) - pow(a[j].y - a[i].y, 2));
			if (distanceMax < distance) {
				c = a[i];
				b = a[j];
				distanceMax = distance;
			}

		}
	}

	FILE* fp = fopen(filename, "w");
	if (!fp) {
		cout << "Chua mo duoc file!";
		return 0;
	}

	fprintf(fp, "%d %d\n", b.x, b.y);
	fprintf(fp, "%d %d", c.x, c.y);
	fclose(fp);

	
}
bool readFile(const char* filename, int a[], int &n) {
	FILE* fp = fopen(filename, "r");

	if (!fp) {
		cout << "Chua mo duoc file!";
		return 0;
	}

	fscanf(fp, "%d \n", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fp, "%d ", &a[i]);
	}fclose(fp);
	return 1;
}

bool writeFile(const char* filename, int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	FILE* fp = fopen(filename, "w");
	if (!fp) {
		cout << "Chua mo duoc file!";
		return 0;
	}

	fprintf(fp, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d ", a[i]);
	}
	fclose(fp);
	return 1;
}
int main() {
	Point a[100];
	int n;
	readListPoint("input.txt", a, n);
	findMostDistance("output2.txt", a, n);


	return 0;
}