#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cassert>
using namespace std;

class Stack {
private:
	int* ptr;
	int capacity;
	int size;
public:
	// constructor
	Stack();
	Stack(int capacity);
	// destructor
	~Stack();
	// Them phan tu vao stack, them vao cuoi
	void push(const int& element);
	// Lay phan tu khoi stack, Lay ra o cuoi theo LIFO
	int pop();
	void print() {
		for (int i = 0; i < size; i++) {
			cout << ptr[i] << " ";
		}
	}
};

#endif // !STACK_H

