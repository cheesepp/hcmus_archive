#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "SinhVien.h"
#include <cassert>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
	SinhVien data;
	Node* next;
};

class List {
private:
	Node* Head;
	int count;
	Node* makeNode(const string& val);
public:
	List();
	~List();
	void insert(int pos, const string& val);
	void erase(int pos);
	string get(int pos) const;
	void print() const;
	int size() const;
};
#endif // !

