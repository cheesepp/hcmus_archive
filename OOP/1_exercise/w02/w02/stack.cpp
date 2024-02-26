#include <iostream>
using namespace std;



class Node {
private:
	int data;
	Node* pNext;
public:
	Node();
	Node(int);
	~Node();
	void setter_data(int);
	int getter_data();
	void setter_pNext(Node*);
	Node* getter_pNext();
	Node* CreateNode(int);

};

Node::Node()
{
	data = 0;
	pNext = NULL;
}

Node::Node(int data_init)
{
	pNext = NULL;
	data = data_init;
}

Node::~Node()
{
	delete pNext;
}


int Node::getter_data()
{
	return data;
}

void Node::setter_data(int set)
{
	data = set;
}

void Node::setter_pNext(Node* pNext_init)
{
	pNext = pNext_init;
}

Node* Node::getter_pNext()
{
	if (!this)
		return nullptr;

	return pNext;
}


Node* Node::CreateNode(int data)
{
	Node* newNode = new Node(data);
	return newNode;
}



class stack {
private:
	Node* top;
public:
	stack();
	stack(int);
	~stack();
	Node* getter_top();
	void setter_top(Node*);
	void print();
	void push(int x);
	void pop();
	int getTop();
	bool isEmpty();
	int getsize();
};


stack::stack()
{
	top = NULL;
}
stack::stack(int init_data)
{
	top = new Node(init_data);
}

stack::~stack() {
	if (!top)
		return;
	Node* cur1 = top;
	Node* cur2 = cur1->getter_pNext();

	while (!cur2)
	{
		delete cur1;
		cur1 = cur2;
		if (!cur2)
			break;
		cur2 = cur2->getter_pNext();
	}
}

Node* stack::getter_top()
{
	return top;
}

void stack::setter_top(Node* top_set)
{
	top = top_set;
}

void stack::print()
{
	cout << "Stack: ";
	Node* cur = top;
	while (cur != NULL)
	{
		cout << cur->getter_data() << ' ';
		cur = cur->getter_pNext();
	}
	cout << endl;
}

void stack::push(int x)
{
	Node* newtop = new Node(x);

	newtop->setter_pNext(top);
	top = newtop;
}

void stack::pop()
{
	if (isEmpty())
	{
		cout << "This stack is currently empty." << endl;
		return;
	}

	Node* popNode = top;
	top = top->getter_pNext();
	delete popNode;
}


int stack::getTop()
{
	return top->getter_data();
}

bool stack::isEmpty()
{
	return !top;
}

int stack::getsize()
{
	int countElements = 0;
	Node* cur = top;
	while (cur != NULL)
	{
		countElements++;

		cur = cur->getter_pNext();
	}
	return countElements;
}



int main()
{
	stack test1;
	test1.push(8);

	cout << "Size of this stack: " << test1.getsize() << endl;

	test1.print();

	test1.push(8);
	test1.push(7);
	test1.push(6);
	test1.push(5);
	test1.push(4);
	test1.push(3);

	cout << "Size of this stack after push some elements: " << test1.getsize() << endl;
	test1.print();

	test1.pop();
	cout << "Size of this stack after once pop: " << test1.getsize() << endl;
	test1.print();




	return 0;
}