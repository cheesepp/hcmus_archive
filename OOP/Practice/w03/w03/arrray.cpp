#include "array.h"

MyIntArray::MyIntArray() {
	size = 0;
	pArr = NULL;
}

MyIntArray::MyIntArray(int sz) {
	size = sz;
	pArr = new int[size];
}

MyIntArray::MyIntArray(const MyIntArray& arr) {
	cout << "\nGoi copy constructor\n";
	if (this != &arr) {
		if (size > 0) {
			delete[] pArr;
		}
		size = arr.size;
		if (size > 0) {
			pArr = new int[size];
			for (int i = 0; i < size; i++) {
				pArr[i] = arr.pArr[i];
			}
		}
	}
}

MyIntArray::~MyIntArray() {
	size = 0;
	delete[] pArr;
	cout << "\nDestructed!";
}

int& MyIntArray::operator[] (int position) {
	return pArr[position];
}

MyIntArray& MyIntArray::operator= (const MyIntArray& arr) {
	if (this != &arr) {
		if (size > 0) {
			delete[] pArr;
		}
		size = arr.size;
		if (size > 0) {
			pArr = new int[size];
			for (int i = 0; i < size; i++) {
				pArr[i] = arr.pArr[i];
			}
		}
	}
	return *this;
}

void MyIntArray::input() {
	for (int i = 0; i < size; i++) {
		cout << "Nhap phan tu " << i + 1 << ": ";
		cin >> pArr[i];
	}
}

void MyIntArray::print() {
	for (int i = 0; i < size; i++) {
		cout << pArr[i] << " ";
	}
}
