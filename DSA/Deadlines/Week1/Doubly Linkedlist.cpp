#include<iostream>
using namespace std;

struct DNode {
	int key;
	DNode* pNext;
	DNode* pPrev;
};

struct DList {
	DNode* pHead;
	DNode* pTail;
};

DNode* createNode(int data)
{
	DNode* p = new DNode();
	p->key = data;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

DList* createList(DNode* pNode)
{
	DList* l = new DList();
	l->pHead = l->pTail = pNode;
	return l;
}

bool addHead(DList*& l, int data)
{
	DNode* p = createNode(data);
	if (l->pHead == NULL)
	{
		l->pHead = l->pTail = p;
		return true;
	}
		p->pNext = l->pHead;
		l->pHead->pPrev = p;
		l->pHead = p;
	
	return true;
}

bool addTail(DList*& l, int data)
{
	if (l->pHead == NULL)
	{
		addHead(l, data);
		return true;
	}
	DNode* p = createNode(data);
	l->pTail->pNext = p;
	p->pPrev = l->pTail;
	l->pTail = p;
	return true;
}

void removeHead(DList*& l)
{
	if (l->pHead == NULL)
	{
		cout << "Danh sach rong!";
		return;
	}
	DNode* q = l->pHead;
	if (l->pHead->pNext != NULL)
	{
		l->pHead = l->pHead->pNext;
		l->pHead->pPrev = NULL;
	}
	delete q;
}

void removeTail(DList*& l)
{
	if (l->pHead == NULL)
	{
		cout << "Empty doubly linkedlist!";
		return;
	}
	DNode* q = l->pTail;
	l->pTail = l->pTail->pPrev;
	l->pTail->pNext = NULL;
	delete q;
}

void removeAll(DList*& l)
{
	if (l->pHead == NULL)
	{
		cout << "Empty doubly linkedlist!";
		return;
	}
	while (l->pHead != NULL) {
		DNode* q = l->pHead;
		l->pHead = q->pNext;
		delete q;
	}
	cout << endl << "All nodes are deleted successfully.\n";
}

void removeBefore(DList*& l, int val)
{
	if (l->pHead->key == val) return;
	DNode* p;
	for (p = l->pHead->pNext; p->pNext->pNext->key != val; p = p->pNext);
	DNode* q = p->pNext;
	p->pNext = p->pNext->pNext;
	p->pNext->pNext->pPrev = p;
	delete q;
}

void removeAfter(DList*& l, int val)
{
	DNode* p;
	for (p = l->pHead; p->key != val && p != NULL; p = p->pNext);
	if (p->pNext == NULL)
	{
		cout << "Ngoai pham vi!";
	}
	else if (p->pNext != l->pTail)
	{
	DNode* q = p->pNext;
	p->pNext->pNext->pPrev = p;
	p->pNext = p->pNext->pNext;
	delete q;
	}
	else if(p->pNext == l->pTail)
	{
		removeTail(l);
	}
	
}

bool addPos(DList*& l, int data, int pos)
{
	if (pos == 0) {
		addHead(l, data);
		return true;
	}
	DNode* p = l->pHead;
	int pos1 = 0;
	while (p != NULL && pos1 != pos - 1) {
		p = p->pNext;
		pos1++;
	}
	DNode* q = createNode(data);
	p->pNext->pPrev = q;
	q->pNext = p->pNext;
	p->pNext = q;
	q->pPrev = p;
	return true;
}

void removePos(DList*& l, int pos)
{
	if (pos == 0) {
		removeHead(l);
		return;
	}
	DNode* p = l->pHead;
	int pos1 = 0;
	while (pos1 != pos - 1 && p != NULL) {
		pos1++;
		p = p->pNext;
	}
	if (p != NULL)
	{
		DNode* q = p->pNext;
		p->pNext->pNext->pPrev = p;
		p->pNext = p->pNext->pNext;
		delete q;
	}
}

bool addBefore(DList*& l, int data, int val)
{
	if (l->pHead->key == val)
	{
		addHead(l, data);
		return true;
	}
	DNode* p = l->pHead;
	while (p->pNext->key != val)
	{
		p = p->pNext;
	}
	DNode* add = createNode(data);
	add->pNext = p->pNext;
	add->pPrev = p;
	p->pNext = add;
	return true;
}

bool addAfter(DList* &l, int data, int val)
{
	DNode* p = l->pHead;
	while (p->key != val)
	{
		p = p->pNext;
	}
	DNode* q = createNode(data);
	q->pNext = p->pNext;
	q->pPrev = p;
	p->pNext = q;
	return true;
}

void printList(DList* l)
{
	if (l == NULL) cout << "DANH SACH RONG!";
	for (DNode* p = l->pHead; p != NULL; p = p->pNext)
	{
		cout << p->key << " ";
	}
}

int countElements(DList* l)
{
	int count = 0;
	for (DNode* p = l->pHead; p != NULL; p = p->pNext)
	{
		count++;
	}
	return count;
}

DList* reverseList(DList* l)
{
	DList* reversedList = l;
	DNode* prev = NULL;
	DNode* curr = reversedList->pHead;
	while (curr != NULL)
	{
		prev = curr->pPrev;
		curr->pPrev = curr->pNext;
		curr->pNext = prev;
		curr = curr->pPrev;
	}
	if (prev != NULL)
		reversedList->pHead = prev->pPrev;
	return reversedList;
}

void removeDuplicate(DList*& l)
{
	int pos = 0;
	for (DNode* p = l->pHead; p->pNext != NULL; p = p->pNext)
	{
		int pos1 = pos;
		for (DNode* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (q->key == p->key)
			{
				removePos(l, pos1);
			}
			pos1++;
		}
		pos++;
	}
}


bool removeElement(DList*& l, int key) {
		DNode* p = l->pHead;
	
		while(p != NULL)
		{
		
			if (l->pHead->key == key)
			{
				removeHead(l);
				p = l->pHead;
				continue;
			}
			else if (p->pNext == l->pTail && p->pNext->key == key)
			{
				removeTail(l);
				p = NULL;
				break;
			}
			else if (p->pNext != NULL && p->pNext->key == key)
			{
				DNode* q = p->pNext;
				p->pNext->pNext->pPrev = p;
				p->pNext = p->pNext->pNext;
				delete q;
				continue;	
			}
				p = p->pNext;
		}
		return true;
	}


void input(DList*& l)
{
	int n;
	cout << "Nhap so node: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;
		addTail(l, data);
	}
}

int main()
{
	DList* l = new DList();
	l->pHead = l->pTail = NULL;
	input(l);
	printList(l);
	cout << endl << "ADD HEAD: ";
	int addNum;
	cout << "Nhap so can them: "; cin >> addNum;
	addHead(l, addNum);
	cout << endl;
	printList(l);
	cout << endl << "ADD TAIL: ";
	int addTa;
	cout << "Nhap so can them: "; cin >> addTa;
	addTail(l, addTa);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE HEAD: ";
	removeHead(l);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE TAIL: ";
	removeTail(l);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE AFTER: ";
	removeAfter(l, 3);
	cout << endl;
	printList(l);
	cout << endl << "ADD BEFORE: ";
	int befNum;
	int add;
	cout << "Nhap lan luot so muon them va so no dung truoc: "; cin >> add >> befNum;
	addBefore(l, add, befNum);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE POSITION: ";
	int delPos;
	cout << "Nhap vi tri muon xoa: "; cin >> delPos;
	removePos(l, delPos);
	cout << endl;
	printList(l);
	cout << endl << "ADD POSITION: ";
	int addNu;
	int addPo;
	cout << "Nhap lan luot gia tri va vi tri muon them: "; cin >> addNu >> addPo;
	addPos(l, addNu, addPo);
	cout << endl;
	printList(l);
	cout << endl << "ADD AFTER: ";
	int addAf;
	int addNumber;
	cout << "Nhap lan luot gia tri muon them va nam sau gia tri: "; cin >> addNumber >> addAf;
	addAfter(l, addNumber, addAf);
	cout << endl;
	printList(l);
	cout << endl << "COUNT ELEMENTS: " << countElements(l) << endl;
	cout << "REVERSE DOUBLY LINKED LIST: " << endl; printList(reverseList(l));
	cout << endl << "REMOVE ELEMENT: ";
	int element;
	cout << "Nhap gia tri muon xoa: "; cin >> element;
	removeElement(l, element);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE DUPLICATE: ";
	removeDuplicate(l);
	cout << endl;
	printList(l);
	cout << endl << "REMOVE ALL: ";
	removeAll(l);
	return 0;
}