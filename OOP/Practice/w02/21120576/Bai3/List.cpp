#include "list.h"

List::List() {
	Head = NULL;
	count = 0;
}

List::~List() {
	while (!Head) {
		Node* p = Head;
		Head = Head->next;
		delete p;
	}
}

Node* List::makeNode(const string& val) {
	Node* p = new Node();
	p->data = val;
	p->next = NULL;
	return p;
}

void List::insert(int pos, const string& val) {

	Node* newNode = makeNode(val);
	int countTemp = -1;
	if (pos <= count) {
		if (pos == 0) {
			if (Head == NULL) {
				Head = newNode;
				count++;
				return;
			}
			else {
				newNode->next = Head;
				Head = newNode;
				count++;
				return;
			}
		}
		else {
			for (Node* p = Head; p != NULL; p = p->next) {
				countTemp++;
				if (countTemp == pos - 1) {
					newNode = p->next->next;
					p->next = newNode;
					count++;
					break;
				}
			}
		}
	}
}

void List::erase(int pos) {
	int countTemp = -1;
	if (pos <= count) {
		if (pos == 0) {
			if (Head) {
				Node* p = Head;
				Head = Head->next;
				delete p;
			}
		}
		else {

			for (Node* p = Head; p != NULL; p = p->next) {
				countTemp++;
				if (countTemp == pos - 1) {
					Node* delNode = p->next;
					p->next = p->next->next;
					delete delNode;
					break;
				}
			}
		}
	}
}

string List::get(int pos) const {
	int countTemp = -1;
	if (pos <= count) {
		for (Node* p = Head; p != NULL; p = p->next) {
			countTemp++;
			if (countTemp == pos) {
				return p->data;
			}
		}
	}
}

int List::size() const {
	return count;
}