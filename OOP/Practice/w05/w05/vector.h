#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
using namespace std;

/* vector class template */
template<typename T>
class vector {
private:
	T* ptr;
	int capacity;
	int sz;
public:

	// Constructors
	vector();
	vector(int cap);
	~vector();
	// utilities methods
	/* operator[] */
	T& operator[](int n);
	/* Expand extra memory */
	void reserve(int newalloc);
	// input, output
	void push(const T& element);
	void erase(int pos);
	void print();
	int getCapacity() const;
	int getSz() const;
	void setCapacity(int cap);
	void setSz(int _sz);
};

#endif

