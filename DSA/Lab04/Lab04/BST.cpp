// Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
using namespace std;

struct NODE {
    int key;
    NODE* pLeft;
    NODE* pRight;
};

// 1. Create node
NODE* createNode(int data)
{
    NODE* p = new NODE();
    if (p == NULL)
    {
        cout << "Khong du bo nho";
        exit(1);
    }
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

// 2. Add a NODE with given value into a given BST
void Insert(NODE*& pRoot, int x)
{
    NODE* p = createNode(x);
    if (pRoot == NULL)
    {
        pRoot = p;
    }
    else {
        if (x < pRoot->key) {
            Insert(pRoot->pLeft, x);
        }
        else
        {
            Insert(pRoot->pRight, x);
        }
    }
}

// 3. Pre-order Traversal
void NLR(NODE* pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }
    cout << pRoot->key << " ";
    NLR(pRoot->pLeft);
    NLR(pRoot->pRight);
}

// 4. In-order Traversal
void LNR(NODE* pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }
    LNR(pRoot->pLeft);
    cout << pRoot->key << " ";
    LNR(pRoot->pRight);
}

// 5. Post-order Traversal
void LRN(NODE* pRoot)
{
    if (pRoot == NULL)
    {
        return;
    }
    LRN(pRoot->pLeft);
    LRN(pRoot->pRight);
    cout << pRoot->key << " ";
}

// 6. Level-order Traversal
void LevelOrder(NODE* pRoot)
{
    queue<NODE*> queue;
    if (pRoot == NULL) return;
    queue.push(pRoot);
    while (!queue.empty()) 
    {
        NODE* curr = queue.front();
        cout << curr->key << " ";
        if (curr->pLeft != NULL) queue.push(curr->pLeft);
        if (curr->pRight != NULL) queue.push(curr->pRight);
        queue.pop();
    }
}

// 7. Calculate the height of a given Binary Tree
int Height(NODE* pRoot)
{
    if (pRoot == NULL) return 0;
    int heightLeft = Height(pRoot->pLeft) + 1;
    int heightRight = Height(pRoot->pRight) + 1;
    return max(heightLeft, heightRight);
}

// 8. Count the number of NODE from a given Binary Tree
int countNode(NODE* pRoot)
{
    if (pRoot == NULL) return 0;
    int leftNodes = countNode(pRoot->pLeft) + 1;
    int rightNodes = countNode(pRoot->pRight) + 1;
    return leftNodes + rightNodes;
}

// 9. Calculate the total value of all NODEs from a given Binary Tree
int sumNode(NODE* pRoot)
{
    if (pRoot == NULL) return 0;
    int leftNodes = sumNode(pRoot->pLeft);
    int rightNodes = sumNode(pRoot->pRight);
    return leftNodes + rightNodes + pRoot->key;
}

// 10. Find and return a NODE with given value from a given Binary Search Tree
NODE* Search(NODE* pRoot, int x)
{
    NODE* foundNode;
    if (pRoot == NULL)
    {
        return NULL;
    }
    if (pRoot->key == x)
    {
        foundNode = pRoot;
    }
    else if (x > pRoot->key)
    {
        foundNode = Search(pRoot->pRight, x);
    }
    else
    {
        foundNode = Search(pRoot->pLeft, x);
    }
    return foundNode;
    
}

// 11. Remove a NODE with given value from a given Binary Search Tree
int minValue(NODE* pRoot)
{
    NODE* current = pRoot;

    while (current->pLeft != NULL) {
        current = current->pLeft;
    }

    return current->key;
}

void Remove(NODE*& pRoot, int x)
{
    if (pRoot == NULL) return;
    else if (x < pRoot->key) Remove(pRoot->pLeft, x);
    else if (x > pRoot->key) Remove(pRoot->pRight, x);
    else {
        if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
        {
            delete pRoot;
            pRoot = NULL;
        }
        else if (pRoot->pLeft == NULL)
        {
            NODE* temp = pRoot;
            pRoot = pRoot->pRight;
            delete temp;
        }
        else if (pRoot->pRight == NULL)
        {
            NODE* temp = pRoot;
            pRoot = pRoot->pLeft;
            delete temp;
        }
        else
        {
            int temp = minValue(pRoot->pRight);
            pRoot->key = temp;
            Remove(pRoot->pRight, temp);
        }
    }
}

// 12. Initialize a Binary Search Tree from a given array
NODE* createTree(int a[], int n)
{
    NODE* root = new NODE();
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        Insert(root, a[i]);
    }
    return root;
}

// 13. Completely remove a given Binary Search Tree
void removeTree(NODE*& pRoot)
{
    if (pRoot == NULL) return;
    if (pRoot->pLeft != NULL) removeTree(pRoot->pLeft);
    if (pRoot->pRight != NULL) removeTree(pRoot->pRight);
    delete pRoot;
}

// 14. Calculate the height of a NODE with given value: (return -1 if value not exist)
int heightNode(NODE* pRoot, int value)
{
    int count = 0;
    if (pRoot == NULL) return 0;
    if (pRoot->key == value)
    {
        return count;
    }
    if (pRoot->pLeft != NULL && pRoot->key > value)
    {
        ++count;
        return heightNode(pRoot->pLeft, value) + count;
    }
    else if (pRoot->pRight != NULL && pRoot->key < value)
    {
        ++count;
        return heightNode(pRoot->pRight, value) + count;
    }
    return -1;

}

// 15. * Calculate the level of a given NODE
int Level(NODE* pRoot, NODE* p)
{
    if (pRoot == NULL) return 0;
    if (pRoot->key == p->key) return 0;
    if (pRoot->key > p->key) return Level(pRoot->pLeft, p) + 1;
    if (pRoot->key < p->key) return Level(pRoot->pRight, p) + 1;
}

// 16. * Count the number leaves from a given Binary Tree
int countLeaf(NODE* pRoot)
{
    int count = 0;
    if (pRoot == NULL) return count;
    int count1 = countLeaf(pRoot->pLeft);
    int count2 = countLeaf(pRoot->pRight);
    if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
    {
        return count + 1;
    }
    return count1 + count2;

}

// 17. * Count the number of NODE from a given Binary Search Tree which key value is less than a given value
int countLess(NODE* pRoot, int x)
{
    int count = 0;

    if (pRoot == NULL) {
        return 0;
    }
    else if (pRoot->key < x) {
        count++;
        count += countLess(pRoot->pLeft, x);
        count += countLess(pRoot->pRight, x);
    }
    else {
        count += countLess(pRoot->pLeft, x);
    }

    return count; 
}

// 18. * Count the number of NODE from a given Binary Search Tree which key value is greater than a given value
int countGreater(NODE* pRoot, int x)
{
    int count = 0;

    if (pRoot == NULL) {
        return 0;
    }
    else if (pRoot->key > x) {
        count++;
        count += countGreater(pRoot->pLeft, x);
        count += countGreater(pRoot->pRight, x);
    }
    else {
        count += countGreater(pRoot->pLeft, x);
    }

    return count; 
}

// 19. * Determine if a given Binary Tree is Binary Search Tree
bool isLesser(NODE* pRoot, int value)
{
    if (pRoot == NULL) return true;
    if (pRoot->key <= value && isLesser(pRoot->pLeft, value) && isLesser(pRoot->pRight, value))
    {
        return true;
    }
    return false;
}

bool isGreater(NODE* pRoot, int value)
{
    if (pRoot == NULL) return true;
    if (pRoot->key >= value && isGreater(pRoot->pLeft, value) && isGreater(pRoot->pRight, value))
    {
        return true;
    }
    return false;
}

bool isBST(NODE* pRoot)
{
    if (pRoot == NULL) return true;
    if (isLesser(pRoot->pLeft, pRoot->key) && isGreater(pRoot->pRight, pRoot->key) && isBST(pRoot->pLeft) && isBST(pRoot->pRight))
    {
        return true;
    }
    return false;
}

// 20. * Determine if a given Binary Tree is a Full Binary Search Tree
bool isFullBST(NODE* pRoot)
{ 
    if (pRoot == NULL)
        return true;

    if (pRoot->pLeft == NULL && pRoot->pRight == NULL)
        return true;

    if (pRoot->pLeft != NULL && pRoot->pRight != NULL)
    {
        if (isFullBST(pRoot->pLeft) && isFullBST(pRoot->pRight) && isBST(pRoot->pLeft) && isBST(pRoot->pRight))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}





int main()
{
    NODE* root = NULL;
    //Insert(root, 2);
    //Insert(root, 3);
    //Insert(root, 9);
    //Insert(root, 17);
    //Insert(root, 25);
    //Insert(root, 1);
    //LRN(root);
    ///*cout << endl << Height(root);
    //NODE* f = Search(root, 4);
    //cout << endl << f->key;*/
    //Remove(root, 3);
    //cout << endl;
    //LRN(root);
    int a[7] = { 25, 9, 2, 17, 3, 1, 0 };
    root = createTree(a, 7);
    LevelOrder(root);

    cout << endl << heightNode(root, 17);
    cout << endl << Height(root);
    NODE* p = createNode(17);
    cout << endl << Level(root, p);

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
