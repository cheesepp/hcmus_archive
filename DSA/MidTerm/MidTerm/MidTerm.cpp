#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct Animal
{
    string en;
    string vn;
    string ph;
    int loai;
};

struct Node
{
    Animal data;
    Node* pnext;
};

struct LinkedList
{
    Node* pHead;
    Node* pTail;
};

Animal readAnAnimal(ifstream& read)
{
    Animal inf;
    vector<string> info;
    string line;
    if (!read.eof()) {
        for (int i = 0; i < 4; i++) {
            getline(read, line);
            if (line.compare("") != 0)
            {
            info.push_back(line);
            }
            else {
                break;
            }
        }
    }
    if (!info.empty())
    {
    inf.en = info[0];
    inf.vn = info[1];
    inf.ph = info[2];
    inf.loai = stoi(info[3]);

    }
    
    return inf;
}

Node* createNode(Animal animal)
{
    Node* p = new Node();
    if (p == NULL)
    {
        cout << "Khong du bo nho!";
        exit(1);
    }
    p->data.en = animal.en;
    p->data.vn = animal.vn;
    p->data.ph = animal.ph;
    p->data.loai = animal.loai;
    p->pnext = NULL;
    return p;
}

LinkedList* readAnimals(string filename)
{
    //CODE HERE
    LinkedList* animals = new LinkedList();
    animals->pHead = NULL;
    animals->pTail = NULL;
    ifstream read(filename);

    if (!read.is_open())
    {

        cout << "Khong mo duoc file!";
        exit(1);
    }
    while (!read.eof()) 
    {
    Animal animal = readAnAnimal(read);
    Node* p = createNode(animal);
    if (animals->pHead == NULL) {
        animals->pHead = animals->pTail = p;
    }
    else 
    {
        animals->pTail->pnext = p;
        animals->pTail = p;
    }
    }
    return animals;

}

void printAnimals(LinkedList* l)
{
    int count = 0;
    Node* p = l->pHead;
    while (p != NULL)
    {
        cout << p->data.en << endl;
        cout << p->data.vn << endl;
        cout << p->data.ph << endl;
        cout << p->data.loai << endl;
        p = p->pnext;
        count++;
    }
    cout << "DEM:==============" << count << endl;
}

void removeHead(LinkedList*& l)
{
    if (l->pHead == NULL)
    {
        cout << "Remove Done!";
        return;
    }
    Node* p = l->pHead;
    l->pHead = l->pHead->pnext;
    delete p;
    //cout << "ok";
}

void removePos(LinkedList*& l, int pos)
{
    if (pos == 0)
    {
        removeHead(l);
        return;
    }
    int currPos = 0;
    Node* p = l->pHead;
    while (currPos != pos - 1)
    {
        currPos++;
        p = p->pnext;
    }
    Node* q = p->pnext;
    p->pnext = p->pnext->pnext;
    delete q;
}

struct NODE
{
    Animal animal;
    NODE* next;
};

struct LIST
{
    NODE* head;
    NODE* tail;
};

LIST* init()
{
    LIST* list = new LIST();
    list->head = NULL;
    list->tail = NULL;
    return list;
}

NODE* createNODE(Animal animal)
{
    NODE* p = new NODE();
    p->animal.en = animal.en;
    p->animal.vn = animal.vn;
    p->animal.ph = animal.ph;
    p->animal.loai = animal.loai;
    p->next = NULL;
    return p;
}

void addTail(LIST*& list, Animal animal)
{
    NODE* p = createNODE(animal);
    if (list->head == NULL) list->head = list->tail = p;
    else
    {
        list->tail->next = p;
        list->tail = p;
    }
}

LIST** InitializeAnimalList()
{
    LIST** animalList = new LIST* [26];
    Animal animal;

    //assign the default value to the string
    animal.en = "null";
    animal.vn = "null";
    animal.ph = "null";
    animal.loai = -1;

    for (int i = 0; i < 26; i++)
    {
        LIST* list = init();
        animalList[i] = list;
    }
    return animalList;
}

LIST** createHashTable(vector<Animal> animal_list)
{
    LIST** animalList = InitializeAnimalList();

    for (int i = 0; i < animal_list.size(); i++)
    {
        long long index = animal_list[i].en[0] - 48;

        addTail(animalList[index % 26], animal_list[i]);

    }

    return animalList;
}


//void removeDuplicate(LinkedList*& list)
//{
//    //CODE HERE
//    int pos = 0;
//    for (Node* p = list->pHead; p->pnext != NULL; p = p->pnext)
//    {
//        int pos1 = pos;
//        for (Node* q = p->pnext; q != NULL; q = q->pnext)
//        {
//            if (q->data.en.compare(p->data.en) == 0)
//            {
//                removePos(list, pos1);
//            }
//            pos1++;
//        }
//        pos++;
//    }
//
//}

void removeDuplicate(LinkedList*& l)
{
    struct Node* ptr1, * ptr2, * dup;
    ptr1 = l->pHead;

    while (ptr1 != NULL && ptr1->pnext != NULL) {
        ptr2 = ptr1;
        while (ptr2->pnext != NULL) {
            /* nếu trùng thì xóa */
            if (ptr1->data.en == ptr2->pnext->data.en) {
                dup = ptr2->pnext;
                ptr2->pnext = ptr2->pnext->pnext;
                delete (dup);
            }
            else
                ptr2 = ptr2->pnext;
        }
        ptr1 = ptr1->pnext;
    }
}


void printPaths(int** matrix, vector<int>& route, int len_route, int i, int j, int M, int N, unsigned long long &compareCount, unsigned long long &assignCount)
{
    // MxN matrix
    if ((++compareCount && M == 0) || (++compareCount && N == 0))
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
    if ((++compareCount && i + 1 < M))
    {
        printPaths(matrix, route, len_route, i + 1, j, M, N,compareCount, assignCount);
    }

    // move right
    if ((++compareCount && j + 1 < N))
    {
        printPaths(matrix, route, len_route, i, j + 1, M, N, compareCount, assignCount);
    }

    // move diagonally
    if ((++compareCount && i + 1 < M) && (++compareCount && j + 1 < N))
    {
        printPaths(matrix, route, len_route, i + 1, j + 1, M, N, compareCount, assignCount);
    }

    // backtrack
    route.pop_back();
}


void CountAssignmentandComparision(unsigned long long & compareCount, unsigned long long& assignCount)
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

    // Goi ham printPaths
    printPaths(matrix, route, len_route, i, j, M, N, compareCount, assignCount); // Ban co the thay doi dong nay neu co thay doi tham so cua ham

    // In ra so phep gan và so phep so sanh
    // CODE HERE
}

int partition(int* a, int low, int high)
{
    int pivot = a[high]; // pivot  
    int i = (low - 1); // Index of smaller element  

    for (int j = low;j <= high - 1; j++)
    {
        // If current element is smaller than the pivot  
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element  
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
a[] --> aay to be sorted,
low --> Starting index,
high --> Ending index */
void quickSortFunction(int* a, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, a[p] is now
        at right place */
        int pi = partition(a, low, high);

        // Separately sort elements before  
        // partition and after partition 
        quickSortFunction(a, low, pi - 1);
        quickSortFunction(a, pi + 1, high);
    }
}

int kthSmallest(int* arr, int n, int k)
{
    //CODE HERE
    int* temp = arr;
    quickSortFunction(temp, 0, n - 1);
    return temp[1];
}

int main()
{

    // Cau 1
    string filename = "data.txt";
    // 1.1
    LinkedList* list = readAnimals(filename);
    printAnimals(list);
    // 1.2
    cout << "===================REMOVE DUPLICATE" << endl;
    removeDuplicate(list);
    printAnimals(list);
    unsigned long long compareCount = 0;
    unsigned long long assignCount = 0;
    // Cau 2
    CountAssignmentandComparision(compareCount, assignCount);
    cout << "COMPARE: " << compareCount << "ASSIGN: " << assignCount << endl;

    //// Cau 3

    int n = 10;
    int* arr = new int[n] {0, 5, 2, 4, 1, 9, 10, 10, 7, 2};
    int k = 5;

    int res = kthSmallest(arr, n, k);
    cout << res;
    return -1;
}
