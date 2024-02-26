//#include <iostream>
//using namespace std;
//
//// =========================== STACK & QUEUE ===============================
//struct Node {
//	int key;
//	Node* pNext;
//};
//
//struct Node* stack;
//struct Node* queue;
//
//Node* createNode(int data)
//{
//	Node* p = new Node();
//	p->key = data;
//	p->pNext = NULL;
//	return p;
//}
//
//void initialize()
//{
//	stack = NULL;
//	queue = NULL;
//}
//
//bool isEmpty(Node* head)
//{
//	if (head == NULL) return true;
//	return false;
//}
//
//
//int count(Node* head)
//{
//	int count = 0;
//	if (isEmpty(head)) return false;
//	for (Node* p = head; p != NULL; p = p->pNext)
//	{
//		count++;
//	}
//	return count;
//}
//// =================================================================
//
//
//
//// =========================== STACK ===============================
//
//void push(int data)
//{
//	Node* p = createNode(data);
//	if (stack == NULL)
//	{
//		stack = p;
//	}
//	else
//	{
//		p->pNext = stack;
//		stack = p;
//	}
//}
//
//int pop()
//{
//	Node* q = stack;
//	int data = q->key;
//	stack = stack->pNext;
//	delete q;
//	return data;
//}
//
//// ========================================================================
//
//
//// =========================== QUEUE ===============================
//
//void enQueue(int data)
//{
//	Node* p = createNode(data);
//	if (queue == NULL)
//	{
//		queue = p;
//	}
//	else
//	{
//
//		Node* temp = queue;
//		while (temp->pNext != NULL)
//		{
//			temp = temp->pNext;
//		}
//		temp->pNext = p;
//	}
//}
//
//int deQueue()
//{
//	if (queue == NULL) return -1;
//	Node* q = queue;
//	queue = queue->pNext;
//	int data = q->key;
//	delete q;
//	return data;
//}
//// ========================================================================
//
//
//
//int main() {
//	initialize();
//	push(5);
//	push(6);
//	cout << pop() << endl;
//	cout << count(stack) << endl;
//	enQueue(5);
//	enQueue(6);
//	cout << deQueue() << endl;
//	return 0;
//}