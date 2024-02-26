#include "Stack.h"


bool isPrime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// constructor
Stack::Stack() {

	capacity = 5;
	ptr = new int[capacity];
}

Stack::Stack(int _capacity) {
	capacity = _capacity;
	ptr = new int[capacity];
	size = 0;
}

// destructor
Stack::~Stack() {
	delete[]ptr;
	ptr = NULL;
	size = capacity = 0;
}

// Them phan tu vao stack, them vao cuoi
void Stack::push(const int& element) {
	if (!isPrime(element)) {
		throw string("Khong phai la so nguyen to! Khong push vao stack!\n");
	}
	cout << "Them " << element << " vao stack \n";
	if (size != capacity) {
		ptr[size] = element;
		size++;
		return;
	}
	pop();
	push(element);
	throw string("Khong du bo nho de them\n");
	
}

// Lay phan tu khoi stack, lay ra o cuoi theo LIFO
int Stack::pop() {
	int x = ptr[size - 1];
	ptr[size - 1] = 0;
	size--;
	cout << "Da xoa phan tu ra khoi stack!\n";
	return x;
}


//
//int main()
//{
//	Stack s(6);
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(5);
//	s.push(4);
//	s.push(9);
//	s.push(8);
//	cout << s.pop() << endl;
//	cout << s.pop() << endl;
//	cout << s.pop() << endl;
//
//}

