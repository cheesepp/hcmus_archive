

#include <iostream>
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

struct AVLNode
{
    int key;
    AVLNode* pLeft;
    AVLNode* pRight;
    int height;
};

int height(AVLNode* root)
{
    if (root == NULL) return 0;
    return root->height;
}

AVLNode* createNode(int data)
{
    AVLNode* p = new AVLNode();
    if (p == NULL) exit(1);
    p->key = data;
    p->pLeft = NULL;
    p->pRight = NULL;
    p->height = height(p);
    return p;
}

int getBalanceFactor(AVLNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return height(root->pLeft) - height(root->pRight);
}


void rotateLeft(AVLNode*& root)
{
    AVLNode* x = root->pRight;
    AVLNode* y = x->pLeft;

    x->pLeft = root;
    root->pRight = y;

    x->height = max(height(x->pLeft), height(x->pRight)) + 1;
    root->height = max(height(root->pLeft), height(root->pRight)) + 1;
    root = x;
    return;
}
void rotateRight(AVLNode*& root) {
    AVLNode* x = root->pLeft;
    AVLNode* t = x->pRight;

    x->pRight = root;
    root->pLeft = t;

    root->height = max(height(root->pLeft), height(root->pRight)) + 1;
    x->height = max(height(x->pLeft), height(x->pRight)) + 1;

    root = x;
    return;
}

void insertAVL(AVLNode*& root, int data)
{
   
    if (root == NULL)
    {
        AVLNode* p = createNode(data);
        root = p;
        return;
    }
    if (data < root->key)
    {
        insertAVL(root->pLeft, data);
    }
    else if (data > root->key)
    {
        insertAVL(root->pRight, data);
    }

    root->height = max(height(root->pLeft), height(root->pRight)) + 1;

    int factor = getBalanceFactor(root);
    if (factor < -1 && root->pRight->key < data)
    {
        rotateLeft(root);
    }
    else if (factor < -1 && root->pRight->key > data)
    {
        rotateRight(root->pRight);
        rotateLeft(root);
    }
    else if (factor > 1 && root->pLeft->key < data)
    {
        rotateLeft(root->pLeft);
        rotateRight(root);
    }
    else if (factor > 1 && root->pLeft->key > data)
    {
        rotateRight(root);
    }
}

void inOrderTraversal(AVLNode* root)
{
    if (root == NULL) return;
    inOrderTraversal(root->pLeft);
    cout << root->key << " ";
    inOrderTraversal(root->pRight);
}

AVLNode* createAVL(int* arr, int n)
{
    AVLNode* root = new AVLNode();
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        insertAVL(root, arr[i]);
    }
    return root;
}

bool isAVL(AVLNode* root)
{
    if (root == NULL) return true;
    int heightLeft = height(root->pLeft);
    int heightRight = height(root->pRight);
    if (abs(heightLeft - heightRight) <= 1 && isAVL(root->pLeft) && isAVL(root->pRight))
    {
        return true;
    }

    return false;
}




// Cau 2
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

vector<Animal> readAnimals(string filename)
{
    vector<Animal> animals;
    ifstream read(filename);
    if (!read.is_open())
    {
        cout << "Khong mo duoc file!";
        exit(1);

    }
    while (!read.eof())
    {
        Animal animal = readAnAnimal(read);
        animals.push_back(animal);
    }
    read.close();
    return animals;

}

void printAnimals(vector<Animal> animals)
{
    for (int i = 0; i < animals.size(); i++)
    {
        cout << animals[i].en << " - " << animals[i].vn << " - " << animals[i].ph << " - " << animals[i].loai << endl;
    }

}

struct AnimalNode
{
    Animal animal;
    AnimalNode* next;
};

struct List
{
    AnimalNode* head;
    AnimalNode* tail;
};

List* initList()
{
    List* list = new List();
    list->head = NULL;
    list->tail = NULL;
    return list;
}

AnimalNode* createAnimalNode(Animal animal)
{
    AnimalNode* p = new AnimalNode();
    p->animal.en = animal.en;
    p->animal.vn = animal.vn;
    p->animal.ph = animal.ph;
    p->animal.loai = animal.loai;
    return p;
}

void addTail(List*& list, Animal animal)
{
    AnimalNode* p = createAnimalNode(animal);
    if (list->head == NULL) list->head = list->tail = p;
    else
    {
        list->tail->next = p;
        list->tail = p;
    }
}



List** createHashTable(vector<Animal> animals)
{
    List** hashTable = new List * [26];
    for (int i = 0; i < 26; i++)
    {
        hashTable[i] = initList();
    }
    for (int i = 0; i < animals.size(); i++)
    {
        int hashValue = animals[i].en[0] - 48 + 48;
        addTail(hashTable[hashValue % 26], animals[i]);
    }
    return hashTable;
}

// Cau 3

int numOfEdges(vector<vector<int>> matrix)
{
    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            count += matrix[i][j];
        }
    }
    
    return count / 2;
    
}

void dfs(vector<vector<int>> matrix, int start, vector<bool>& visited)
{

    cout << start << " ";

    visited[start] = true;

    for (int i = 0; i < matrix[start].size(); i++) {
        if (matrix[start][i] == 1 && (!visited[i])) {
            dfs(matrix, i, visited);
        }
    }
}

int connectedComponents(vector<vector<int>> matrix, vector<bool>& visited)
{
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (!visited[i])
        {
            ++ans;
            dfs(matrix, i, visited);
        }
    }
    return ans;
}


int minimumEdges(vector<vector<int>> graph, int k)
{
    vector<bool> visited(graph.size(), false);
    vector<vector<bool>> allowed(graph.size());
    int count = 0;
    for (int i = 0; i < allowed.size(); i++)
    {
        for (int j = 0; j < allowed[i].size(); j++)
        {
            allowed[i][j] = true;
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            if (graph[i][j] == 1)
            {
                continue;
            }
            else
            {
                graph[i][j] = 1;
                count++;
                if (count % k != 0) return count;
                else if (allowed[i][j] && connectedComponents(graph, visited) != 2)
                {
                    allowed[i][j] = false;
                    count = 0;
                }
            }
        }
    }
}

int main()
{
    vector<Animal> animals = readAnimals("Animal.txt");
    //printAnimals(animals);
    /*List** hashTable = createHashTable(animals);
    for (AnimalNode* p = hashTable[1]->head; p != NULL; p = p->next)
    {
        cout << p->animal.en << endl;
    }*/
    int arr[6] = { 1,2,3,4,5,6 };
    AVLNode* root = createAVL(arr, 6);
    inOrderTraversal(root);
    cout << endl << isAVL(root);
  
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
















