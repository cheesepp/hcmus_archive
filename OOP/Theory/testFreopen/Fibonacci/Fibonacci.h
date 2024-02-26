#pragma once
#include<iostream>
using namespace std;
class Fibonacci
{
private:
	int size;
	int* elements;
public:
	Fibonacci();
	Fibonacci(int n);
	~Fibonacci();
	void generateFibonacci(int n);
	void print();
};

