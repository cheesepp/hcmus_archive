// w02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define M 500
using namespace std;

// ==================== STACK - USING ARRAY ==========================
class Stack {
private:
    int data[M];
    int n;

public:
    Stack();
    void push(int);
    int pop();
    int top();
    bool isEmpty();
    int size();

};

Stack::Stack() {
    n = 0;
    for (int i = 0; i < n; i++) {
        data[i] = 0;
    }
}

void Stack::push(int x) {
    data[n] = x;
    n++;
}

int Stack::top() {
    return data[n - 1];
}

int Stack::pop() {
    int x = data[n - 1];
    data[n - 1] = 0;
    n--;
    return x;
}

int Stack::size() {
    return n;
}

bool Stack::isEmpty() {
    if (n == 0) {
        return true;
    }
    return false;
}

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
    Stack s;
    s.push(5);
    s.push(6);
    s.push(1);
    cout << endl << s.size() << endl;
    int x = s.pop();
    cout << x << endl;
    int y = s.top();
    cout <<  endl << y << endl;
    cout << endl << s.size()  << endl;
    cout << s.isEmpty();
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
}
