#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string.h>
using namespace std;

struct BabyName
{
    string name;
    string gender;
    int year;
    int count;
};

struct Node
{
    BabyName data;
    Node* pnext;
};

struct LinkedList
{
    Node* pHead;
    Node* pTail;
};

BabyName readABabyNames(ifstream& fin, string line_info)
{
    BabyName babyName;
    stringstream s(line_info);
    string buffer;
    vector<string> readInf;
    if (fin.is_open()) {
        for (int i = 0; i < 4; i++)
        {
            getline(s, buffer, ' ');
            readInf.push_back(buffer);
        }
      
        babyName.name = readInf[0];
        babyName.year = stoi(readInf[1]);
        babyName.gender = readInf[2];
        babyName.count = stoi(readInf[3]);
    }
    
    return babyName;
}

Node* createNode(BabyName babyName)
{
    Node* p = new Node();
    if (p == NULL)
    {
        cout << "Khong du bo nho!";
        exit(1);
    }
    p->data.count = babyName.count;
    p->data.gender = babyName.gender;
    p->data.name = babyName.name;
    p->data.year = babyName.year;
    p->pnext = NULL;
    return p;
}

void printBabyNames(LinkedList* l)
{
    Node* p = l->pHead;
    while (p != NULL)
    {
        cout << p->data.name << " " << p->data.year << " " << p->data.gender << " " << p->data.count << endl;
        p = p->pnext;
    }
}

LinkedList* readBabyNames(string filename)
{
    //CODE HERE
    LinkedList* list = new LinkedList();
    list->pHead = NULL;
    list->pTail = NULL;
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "Khong mo duoc file!";
        exit(1);
   }
    string line_info;
    getline(fin, line_info, '\n');
    while (!fin.eof())
    {
        getline(fin, line_info, '\n');
        BabyName babyName = readABabyNames(fin, line_info);
        Node* p = createNode(babyName);
        if (list->pHead == NULL)
        {
            list->pHead = list->pTail = p;
        }
        else
        {
            list->pTail->pnext = p;
            list->pTail = p;
        }
    }
   
    return list;

}

void addTail(LinkedList*& l, Node* p) {
    if (l->pHead == NULL)
    {
        l->pHead = l->pTail = p;
    }
    else {
        l->pTail->pnext = p;
        l->pTail = p;
    }
}

LinkedList* splitBabyNames(LinkedList* list, int year)
{
    //CODE HERE
    LinkedList* splitA = new LinkedList();
    for (Node* p = list->pHead; p != NULL; p = p->pnext)
    {
        if (p->data.year == year)
        {
            addTail(splitA, p);
        }
    }
    return splitA;

}

LinkedList* mergeLinkedList(LinkedList* list1, LinkedList* list2)
{
    //CODE HERE
    LinkedList* merge = new LinkedList();
    Node* p = list1->pHead;
    Node* q = list2->pHead;
    while (p != NULL && q != NULL)
    {
        if (p->data.name == q->data.name && p->data.gender == q->data.gender)
        {
            int newCount = p->data.count + p->data.count;
            Node* mergeNode = new Node();
            mergeNode->data.gender = p->data.gender;
            mergeNode->data.name = p->data.name;
            mergeNode->data.year = 0;
            mergeNode->data.count = newCount;
            addTail(merge, mergeNode);
            p = p->pnext;
            q = q->pnext;
            continue;
        }

        addTail(merge, p);
        addTail(merge, q);
        p = p->pnext;
        q = q->pnext;
    }

    while (p != NULL)
    {
        addTail(merge, p);
        p = p->pnext;
    }

    while (q != NULL)
    {
        addTail(merge, q);
        q = q->pnext;
    }

    return merge;

}


void printPaths(int** matrix, vector<int>& route, int len_route, int i, int j, int M, int N, unsigned long long &compareCount, unsigned long long &assignCount)
{
    // MxN matrix
    if (++compareCount && M == 0 ||++compareCount && N == 0)
    {
        return;
    }

    // if the last cell is reached
    if ((++compareCount && i == M - 1) && (++compareCount && j == N - 1))
    {
        // print the route
        for (int k = 0;++compareCount && k < len_route; k++)
        {
            ++assignCount;
            cout << route[k] << " ";
        }
        ++assignCount;
        cout << matrix[i][j] << endl;
        return;
    }

    // add the current cell to route
    route.push_back(matrix[i][j]);
    len_route += 1; ++assignCount;

    // move down
    if (++compareCount && i + 1 < M)
    {
        printPaths(matrix, route, len_route, i + 1, j, M, N, compareCount, assignCount);
    }

    // move right
    if (++compareCount && j + 1 < N)
    {
        printPaths(matrix, route, len_route, i, j + 1, M, N, compareCount, assignCount);
    }

    // move diagonally
    if ((++compareCount && i + 1 < M) &&(++compareCount && j + 1 < N))
    {
        printPaths(matrix, route, len_route, i + 1, j + 1, M, N, compareCount, assignCount);
    }

    // backtrack
    route.pop_back();
}


void CountAssignmentandComparision()
{
    int M = 3, N = 3;
    int** matrix = new int* [M];

    for (int i = 0; i < M; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M * N; i++)
    {
        matrix[i / N][i % N] = i;
    }

    vector<int> route;
    int len_route = 0;
    int i = 0, j = 0;

    unsigned long long compareCount = 0;
    unsigned long long assignCount = 0;

    // Goi ham printPaths
    printPaths(matrix, route, len_route, i, j, M, N, compareCount, assignCount); // Ban co the thay doi dong nay neu co thay doi tham so cua ham

    // In ra so phep gan và so phep so sanh
    // CODE HERE
    cout << "So phep so sanh: " << compareCount << endl;
    cout << "So phep gan: " << assignCount << endl;
}


int partition(int*& a, int low, int high)
{
    int pivot = a[high]; 
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
     
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(int* &a, int low, int high)
{
    if (low < high)
    {
       
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int countPairs(int* arr, int n, int k)
{
    //CODE HERE
    int* temp = arr;
    quickSort(temp, 0, n - 1);
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(temp[i] - temp[j]) == k && temp[i] != temp[j])
            {
                count++;
            }
        }
    }
    return count;

}

int main()
{

    // Cau 1
    string filename = "data.txt";
    // 1.1
    LinkedList* list = readBabyNames(filename);
    printBabyNames(list);
    // 1.2
    LinkedList* babyNames1880 = splitBabyNames(list, 1880);
    LinkedList* babyNames1881 = splitBabyNames(list, 1881);
    cout << "================= 1880 ==================" << endl;
    printBabyNames(babyNames1880);
    cout << "================= 1881 ==================" << endl;

    printBabyNames(babyNames1881);

    // 1.3 
    cout << "====================== MERGE LIST =============================" << endl;
    LinkedList* mergedList = mergeLinkedList(babyNames1880, babyNames1881);
    printBabyNames(mergedList);

        // Cau 2
        CountAssignmentandComparision();

    // Cau 3

    int n = 5;
    int* arr = new int[n] {3, 1, 4, 1, 5};
    int k = 2;

    int res = countPairs(arr, n, k);
    cout << res << endl;

    return -1;
}
