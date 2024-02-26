#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pLeft;
	NODE* pRight;
	int height;
};

int Height(NODE* pRoot)
{
	if (pRoot == NULL) return 0;
	int heightLeft = Height(pRoot->pLeft) + 1;
	int heightRight = Height(pRoot->pRight) + 1;
	return max(heightLeft, heightRight);
}


NODE* createNode(int data)
{
	NODE* p = new NODE();
	if (p == NULL) exit(1);
	p->key = data;
	p->pLeft = NULL;
	p->pRight = NULL;
    p->height = Height(p);
    return p;
}

// Get Balance factor of node  
int getBalanceFactor(NODE* pRoot) {
    if (pRoot == NULL) return 0;
    return Height(pRoot->pLeft) - Height(pRoot->pRight);
}

// rotate right
void rotateRight(NODE*& pRoot) {
    NODE* x = pRoot->pLeft;
    NODE* temp = x->pRight;

    x->pRight = pRoot;
    pRoot->pLeft = temp;

}


// rotate left
void rotateLeft(NODE*& pRoot) {
    NODE* y = pRoot->pRight;
    NODE* temp = y->pLeft;

    y->pLeft = pRoot;
    pRoot->pRight = temp;

}

// 2. Add a NODE with given value into a given BST
void Insert(NODE*& pRoot, int x)
{
    NODE* p = createNode(x);
    if (pRoot == NULL)
    {
        pRoot = p;
        pRoot->height = Height(pRoot);
    }

    if (x < pRoot->key) {
        Insert(pRoot->pLeft, x);
    }
    else if (x > pRoot->key)
    {
        Insert(pRoot->pRight, x);
    }
    else
    {
        cout << "No duplicate values allowed!" << endl;
    }

    int bf = getBalanceFactor(pRoot);
    // Left Left Case  
    if (bf > 1 && p->key < pRoot->pLeft->key)
        rotateRight(pRoot);

    // Right Right Case  
    if (bf < -1 && p->key > pRoot->pRight->key)
        rotateLeft(pRoot);

    // Left Right Case  
    if (bf > 1 && p->key > pRoot->pLeft->key) {
        rotateLeft(pRoot->pLeft);
        rotateRight(pRoot);
    }

    // Right Left Case  
    if (bf < -1 && p->key < pRoot->pLeft->key) {
        rotateRight(pRoot->pRight);
        rotateLeft(pRoot);
    }
}

// Supported function to find min value at the right sub tree
int minValue(NODE* pRoot)
{
    NODE* current = pRoot;

    while (current->pLeft != NULL) {
        current = current->pLeft;
    }

    return current->key;
}

// Remove a NODE from AVL
void* Remove(NODE* &pRoot, int x) {
    if (pRoot == NULL) {
        return NULL;
    }
   
    else if (x < pRoot->key) {
        Remove(pRoot->pLeft, x);
    }
  
    else if (x > pRoot->key) {
        Remove(pRoot->pRight, x);
    }
  
    else {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->pLeft == NULL) {
            NODE* temp = pRoot;
            pRoot = pRoot->pRight;
            delete temp;
        }
        else if (pRoot->pRight == NULL) {
            NODE* temp = pRoot;
            pRoot = pRoot->pLeft;
            delete temp;
        }
        else {
          
            int temp = minValue(pRoot->pRight);
         
            pRoot->key = temp;
            
            Remove(pRoot->pRight, temp);
           
        }
    }

    // Find balance factor
    int bf = getBalanceFactor(pRoot);
    if (bf == 2 && getBalanceFactor(pRoot->pLeft) >= 0)
         rotateRight(pRoot);
    else if (bf == 2 && getBalanceFactor(pRoot->pLeft) == -1) {
        rotateLeft(pRoot->pLeft);
        rotateRight(pRoot);
    }
    else if (bf == -2 && getBalanceFactor(pRoot->pRight) <= 0)
        rotateLeft(pRoot);
    else if (bf == -2 && getBalanceFactor(pRoot->pRight) == 1) {
        rotateRight(pRoot->pRight);
        rotateLeft(pRoot);
    }
}

bool isAVL(NODE* pRoot)
{
    if (pRoot == NULL) return true;
    int heightLeft = Height(pRoot->pLeft);
    int heightRight = Height(pRoot->pRight);
    if (abs(heightLeft - heightRight) <= 1 && isAVL(pRoot->pLeft) && isAVL(pRoot->pRight))
    {
        return true;
    }

    return false;
}
int main() {
    NODE* root = createNode(7);
    root->pLeft = createNode(6);
    root->pRight = createNode(12);
    root->pLeft->pLeft = createNode(4);
    root->pLeft->pRight = createNode(5);
    root->pRight->pRight = createNode(13);
    if (isAVL(root))
        cout << "The Tree is AVL Tree" << endl;
    else
        cout << "The Tree is not AVL Tree " << endl;
    NODE* root1 = createNode(7);
    root1->pLeft = createNode(6);
    root1->pRight = createNode(12);
    root1->pLeft->pLeft = createNode(4);
    root1->pLeft->pRight = createNode(5);
    root1->pRight->pRight = createNode(13);
    root1->pRight->pRight->pRight = createNode(26);
    if (isAVL(root1))
        cout << "The Tree is AVL Tree" << endl;
    else
        cout << "The Tree is not AVL Tree " << endl;
    return 0;
}