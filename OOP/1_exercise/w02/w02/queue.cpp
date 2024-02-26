// w02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define M 500
using namespace std;

// ============================ QUEUE - USING LINKED LIST =============================

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node();
    p->data = x;
    p->next = NULL;
    return p;
}

class Queue {
private:
    Node* head;
public:
    Queue();
    ~Queue();
    void enQueue(int);
    void deQueue();
    int top();
    bool isEmpty();
    int size();
};

Queue::Queue() {
    head = NULL;
}

void Queue::enQueue(int x) {
    Node* p = createNode(x);
    if (head == NULL) head = p;
    else {
        Node* cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = p;
    }
}

void Queue::deQueue() {
    Node* p = head;
    head = head->next;
    delete p;
}

int Queue::top() {
    return head->data;
}

bool Queue::isEmpty() {
    return head == NULL;
}

int Queue::size() {
    int count = 0;
    if (head == NULL) return 0;
    for (Node* p = head; p != NULL; p = p->next) {
        count++;
    }
    return count;
}

Queue::~Queue()
{
    while (!head)
    {
        deQueue();
    }
}

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    cout << q.size() << endl;
    cout << q.top() << " " << q.size() << endl;
    q.deQueue();
    cout << q.top() << " " << q.size() << endl;
    q.deQueue();
    cout << q.size() << endl;
    cout << q.isEmpty();
    return 0;
}
