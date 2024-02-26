#include "Fibonacci.h"

Fibonacci::Fibonacci()
{
    size = 0;
    elements = nullptr;
}

Fibonacci::Fibonacci(int n)
{
    size = n;
    elements = new int[size];
}

Fibonacci::~Fibonacci()
{
    if(elements != nullptr)
     delete[]elements;
    size = 0;
}

void Fibonacci::generateFibonacci(int n)
{
    if (size == 0) {
        size = n;
        elements = new int[size];
    }

    elements[0] = 0;
     elements[1] = 1;

    int temp = 2;
    int F1 = elements[1];
    int F0 = elements[0];
    while (temp < n) {
        elements[temp] =F1 + F0;
        F1 = elements[temp];
        F0 = elements[temp - 1];
        temp += 1;
    }
}

void Fibonacci::print()
{
    for (int i = 0; i < size; i++) {
        cout << elements[i] << " ";
    }
}
