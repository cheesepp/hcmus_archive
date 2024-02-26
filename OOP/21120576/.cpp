#include "vector.h"
#include "vector.h"

template<typename T>
vector<T>::vector() {
	capacity = 100;
	sz = 0;
	ptr = new T[capacity];
}

template<typename T>
vector<T>::vector(int cap) {
	capacity = cap;	
	sz = 0;
	ptr = new T[capacity];
}

template<typename T>
vector<T>::~vector() {
	if (sz > 0) {
		delete[]ptr;
	}
}

template<typename T>
T& vector<T>::operator[](int n) {
	return ptr[n];
}

template<typename T>
void vector<T>::reserve(int newalloc) {
	capacity += newalloc;
	if (sz >= capacity) {
		cout << "Khong the cap phat phan tu vi vuot qua suc chua (" << capacity << ")!\n";
		return;
	}
}

template<typename T>
void vector<T>::push(const T& element) {
	if (sz >= capacity) {
		cout << "Khong the them phan tu vi vuot qua suc chua (" << capacity << ")!\n";
		return;
	}
	ptr[sz] = element;
	sz++;
}

template<typename T>
void vector<T>::print() {
	for (int i = 0; i < sz; i++) {
		cout << ptr[i] << " ";
	}
}

template<typename T>
int vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
int vector<T>::getSz() const
{
	return sz;
}

template<typename T>
void vector<T>::setSz(int _sz) {

	sz = _sz;
}

template<typename T>
void vector<T>::setCapacity(int cap) {
	capacity = cap;
}


template class vector<string>;
template class vector<int>;
template class vector<double>;
