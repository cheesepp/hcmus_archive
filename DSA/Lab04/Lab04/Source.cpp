//#include "iostream"
//struct NODE {
//	int key;
//	NODE* pLeft;
//	NODE* pRight;
//	int height;
//};
//
//int Height(NODE* ptr)
//{
//	if (ptr == nullptr)
//		return 0;
//	return ptr->height;
//}
//NODE* createNode(int data)
//{
//	NODE* ptr = new NODE();
//	ptr->key = data;
//	ptr->pLeft = nullptr;
//	ptr->pRight = nullptr;
//	ptr->height = 1;
//	return ptr;
//}
//int max(int a, int b)
//{
//	if (a > b)
//		return a;
//	else return b;
//}
//int isBalance(NODE* root)
//{
//	if (root = nullptr)
//		return 0;
//	return root->pLeft->height - root->pRight->height;
//
//}
//
//void rotateLeft(NODE*& root)
//{
//	NODE* r = root->pRight;
//	NODE* tree = r->pLeft;
//
//	r->pLeft = root;
//	root->pRight = tree;
//
//	r->height = max(Height(r->pLeft), Height(r->pRight)) + 1;
//	root->height = max(Height(root->pLeft), Height(root->pRight)) + 1;
//	root = r;
//	return;
//}
//void rotateRight(NODE*& root) {
//	NODE* l = root->pLeft;
//	NODE* t = l->pRight;
//
//	l->pRight = root;
//	root->pLeft = t;
//
//	root->height = max(Height(root->pLeft), Height(root->pRight)) + 1;
//	l->height = max(Height(l->pLeft), Height(l->pRight)) + 1;
//
//	root = l;
//	return;
//}
//int findTheSmallestNodeInRightSubTree(NODE* pRoot)
//{
//	NODE* current = pRoot;
//
//	while (current->pLeft != NULL) {
//		current = current->pLeft;
//	}
//
//	return current->key;
//}
//void Delete(NODE*& pRoot, int x)
//{
//	if (pRoot == nullptr)
//	{
//		pRoot = createNode(x);
//		return;
//	}
//	else if (pRoot->key > x)
//	{
//		Delete(pRoot->pLeft, x);
//	}
//	else if (pRoot->key < x)
//	{
//		Delete(pRoot->pRight, x);
//	}
//	else
//	{
//		if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
//		{
//			delete pRoot;
//			pRoot = nullptr;
//
//		}
//		if (pRoot->pLeft == nullptr && pRoot->pRight != nullptr)
//		{
//			NODE* temp = pRoot;
//			pRoot = pRoot->pRight;
//			delete temp;
//
//		}
//		if (pRoot->pLeft != nullptr && pRoot->pRight == nullptr)
//		{
//			NODE* temp = pRoot;
//			pRoot = pRoot->pLeft;
//			delete temp;
//
//		}
//		if (pRoot->pLeft != nullptr && pRoot->pRight != nullptr)
//		{
//			int temp = findTheSmallestNodeInRightSubTree(pRoot->pRight);
//			pRoot->key = temp;
//			Delete(pRoot->pRight, temp);
//		}
//	}
//	if (pRoot == nullptr)
//		return;
//
//	pRoot->height = max(Height(pRoot->pLeft), Height(pRoot->pRight)) + 1;
//	int bal = isBalance(pRoot);
//
//	if (bal < -1 && isBalance(pRoot->pRight) < 0)
//	{
//		return rotateLeft(pRoot);
//
//	}
//	if (bal > 1 && isBalance(pRoot->pLeft) > 0)
//	{
//		return rotateRight(pRoot);
//
//	}
//	if (bal < -1 && isBalance(pRoot->pRight) >= 0)
//	{
//		rotateRight(pRoot->pRight);
//		return rotateLeft(pRoot);
//	}
//	if (bal > 1 && isBalance(pRoot->pLeft) <= 0)
//	{
//		rotateLeft(pRoot->pLeft);
//		return rotateRight(pRoot);
//	}
//	return;
//}
//void Insert(NODE*& pRoot, int x)
//{
//	if (pRoot == nullptr)
//	{
//		NODE* ptr = createNode(x);
//		pRoot = ptr;
//		return;
//	}
//	else if (pRoot->key > x)
//	{
//		Insert(pRoot->pLeft, x);
//
//	}
//	else if (pRoot->key < x)
//	{
//		Insert(pRoot->pRight, x);
//	}
//	else return;
//	pRoot->height = max(Height(pRoot->pLeft), Height(pRoot->pRight)) + 1;
//	int bal = isBalance(pRoot);
//
//	if (bal < -1 && x > pRoot->pRight->key)
//	{
//		return rotateLeft(pRoot);
//
//	}
//	if (bal > 1 && pRoot->pLeft->key > x)
//	{
//		return rotateRight(pRoot);
//
//	}
//	if (bal < -1 && pRoot->pRight->key>x)
//	{
//		rotateRight(pRoot->pRight);
//		return rotateLeft(pRoot);
//	}
//	if (bal > 1 && pRoot->pLeft->key < x)
//	{
//		rotateLeft(pRoot->pLeft);
//		return rotateRight(pRoot);
//	}
//	return;
//}
//bool isBST(NODE* pRoot)
//{
//	if (pRoot == nullptr)
//		return true;
//	if (pRoot->pLeft != nullptr && pRoot->key < pRoot->pLeft->key)
//		return false;
//	if (pRoot->pRight != nullptr && pRoot->key > pRoot->pRight->key)
//	{
//		return false;
//	}
//	bool l = isBST(pRoot->pLeft);
//	bool r = isBST(pRoot->pRight);
//	return (l && r);
//}
//bool isAVL(NODE* pRoot)
//{
//	if (pRoot == nullptr)
//		return true;
//	if (isBST(pRoot) == false)
//		return false;
//	if ((Height(pRoot->pLeft) - Height(pRoot->pRight) > 1) || (Height(pRoot->pLeft) - Height(pRoot->pRight) < -1))
//		return false;
//	bool l = isAVL(pRoot->pLeft);
//	bool r = isAVL(pRoot->pRight);
//	return (l && r);
//}
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char abc[5] = "abcd";
    cout << (int)abc;

    return 0;
}
