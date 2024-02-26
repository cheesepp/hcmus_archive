// Lab06 - Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <sstream>
#include<fstream>
#include<queue>

using namespace std;

// Cau 1
vector<int> readRow(string line)
{
    vector<int> arr;
    stringstream s(line);
    string buffer;
    for (int i = 0; i < 9; i++)
    {
        getline(s, buffer, ' ');
        arr.push_back(stoi(buffer));
    }
    return arr;
}

vector<vector<int>> readAdjacencyMatrix(string file_name, int &size)
{
    vector<vector<int>> matrix;
    ifstream in(file_name);
    if (in.is_open())
    {
        string line_info;
        getline(in, line_info, '\n');
        size = stoi(line_info);
        while (!in.eof())
        {
            getline(in, line_info, '\n');
            vector<int> row = readRow(line_info);
            matrix.push_back(row);
        }
    }
    in.close();
    return matrix;
}

// Cau 2
vector<int> readRow2(string info)
{
    vector<int> line;
    stringstream s(info);
    string buffer;
    getline(s, buffer);
    for(int i = 0; i < buffer.length(); i++)
    {
        if (buffer == "") line.push_back(-1);
        if (buffer[i] != ' ')
        {
            int c = int(buffer[i]) - 48;
            line.push_back(c);
        }
    }
    return line;

}


vector<vector<int>> readAdjacencyList(string file_name, int &size)
{
    vector<vector<int>> matrix;
    ifstream in(file_name);
    if (in.is_open())
    {
        string line_info;
        getline(in, line_info, '\n');
        size = stoi(line_info);
        while (getline(in, line_info, '\n'))
        {
            if (line_info.empty()) {
                vector<int> row(1, -1);
                matrix.push_back(row);
            }
            else
            {
                vector<int> row = readRow2(line_info);
                matrix.push_back(row);
            }
          
        }
    }
    in.close();
    return matrix;
}

bool isDirected(vector<vector<int>> matrix)
{
    bool dir = false;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] != matrix[j][i])
                return true;
        }
    }
    return false;
}

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
    if (!isDirected(matrix))
    {
        return count / 2;
    }
    return count;
}

int numOfVertices(vector<vector<int>> matrix)
{
    return matrix.size();
}

int sumDegreeOfGraph(vector<vector<int>> matrix)
{
    if (!isDirected(matrix))
    {
        return 2 * numOfEdges(matrix);
    }
    return numOfEdges(matrix);
}

vector<int> isolatedVertices(vector<vector<int>> matrix)
{
    vector<int> list;
    for (int i = 0; i < matrix.size(); i++)
    {
        int isIsolated = 1;
        for (int j = 0; j < matrix.size(); j++)
        {
            if ((matrix[i][j] == 0 && matrix[j][i] == 0) || (i == j && matrix[i][j] != 0))
            {
                continue;
            }
            else
            {
                isIsolated = 0;
                break;
            }
        }
        if (isIsolated) list.push_back(i);
    }
    return list;
}

vector<int> leafVertices(vector<vector<int>> matrix)
{
    vector<int> list;
    int count = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (isDirected(matrix))
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (matrix[i][j] == 1 && matrix[j][i] == 0 || matrix[j][i] == 1 && matrix[i][j] == 1) count++;
            }
        }
        else
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (i != j && matrix[i][j] == 1) count++;
            }
            if (count == 1) list.push_back(i);
        }
       
    }
    return list;
}

bool isCircularGraph(vector<vector<int>> matrix)
{
    bool isCirGraph = false;
    int numEdges = 0;
    if (!isDirected(matrix))
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j])
                    count++;
            }
            if (count == 2)
            {
                isCirGraph = true;
                numEdges += 1;

            }
            else
            {
                isCirGraph = false;
                break;
            }
        }
        if (isCirGraph && numEdges == matrix.size())
        {
            return true;
        }
    }
    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            int count1 = 0;
            int count2 = 0;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j]==1) count1++;
                if (matrix[j][i]==1) count2++;
            }
            if (count1 == count2)
            {
                isCirGraph = true;
                numEdges += count1 + count2;

            }
            else
            {
                isCirGraph = false;
                break;
            }
            if (isCirGraph && numEdges == matrix.size())
                return true;
        }
    }
 
    return false;
}

int countEdges(vector<vector<int>> matrix)
{
    int count = 0;
    if (isDirected(matrix))
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[j].size(); j++)
            {
                count += matrix[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                count += matrix[i][j];
            }
        }
        count = count / 2;
    }
    return count;
}


bool isCompleteGraph(vector<vector<int>> matrix)
{
    int numCompleteEdges = matrix.size() * (matrix.size() - 1) / 2;
    if (numOfEdges(matrix) == numCompleteEdges) return true;
    return false;
}

bool isBiGraph(vector<vector<int>> matrix, int src)
{
    // Create a color array to store colors
        // assigned to all vertices. Vertex
        // number is used as index in this array.
        // The value '-1' of colorArr[i]
        // is used to indicate that no color
        // is assigned to vertex 'i'. The value 1
        // is used to indicate first color
        // is assigned and value 0 indicates
        // second color is assigned.
    vector<int> colorArr;
    for (int i = 0; i < matrix.size(); ++i)
        colorArr[i] = -1;

    
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex
    // numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices
    // in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

        // Return false if there is a self-loop
        if (matrix[u][u] == 1)
            return false;

        // Find all non-colored adjacent vertices
        for (int v = 0; v < matrix.size(); ++v)
        {
            // An edge from u to v exists and
            // destination v is not colored
            if (matrix[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (matrix[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent 
    // vertices can be colored with alternate color
    return true;
}

// function to perform DFS on the graph
void dfs(vector<vector<int>> matrix,int start, vector<bool>& visited)
{

    // Print the current node
    cout << start << " ";

    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    for (int i = 0; i < matrix[start].size(); i++) {

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (matrix[start][i] == 1 && (!visited[i])) {
            dfs(matrix, i, visited);
        }
    }
}

void bfs(vector<vector<int>> matrix, int start, vector<bool>& visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for (int i = 0; i < matrix[v].size(); i++)
        {
            if (matrix[v][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
}

// Function to perform BFS on the graph
void bfs2(vector<vector<int>> adj, int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];

        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {

                // Push the adjacent node to the queue
                q.push_back(i);

                // Set
                visited[i] = true;
            }
        }
    }
}

bool isCyclic(int src, int prt, vector<vector<int>> vec, vector<bool>& visited)
{
    visited[src] = true;
    for (auto i : vec[src])
    {
        if (!visited[i])
        {
            if (isCyclic(i, src, vec, visited)) return true;
        }
        else if (i != prt) return true;

    }
    return false;

}

bool isTree(int n, vector<vector<int>> vec)
{
    vector<bool> visited(n, false);
    int startNode = 0;
    if (isCyclic(startNode, -1, vec, visited)) return false;

    for (int u = 0; u < n; u++)
    {
        if (!visited[u]) return false;
    }
    return true;
}


void connectedComponentsDirectedGraph(vector<vector<int>> matrix, vector<bool>& visited)
{
    int ans = 0;
    int tree = 0;
    vector<bool> checked(matrix.size(), false);
    for (int i = 0; i < matrix.size(); i++)
    {
        if (!visited[i])
        {
            ++ans;
            cout << "Connected component at " << ans << endl;
            dfs(matrix, i, visited);
        }
        int size = 0;
        for (int j = 0; j < matrix.size(); j++)
        {

            if (!checked[j] && visited[j])
            {
                checked[j] = true;
                size++;
            }
            if (checked[j])
            {
                if (numOfEdges(matrix) == matrix.size() - 1)
                {
                    tree++;
               }
            }
        }

    }

    cout << "Num of tree: " << tree;
    
 }

struct EDGE
{
    int x;
    int y;
    int w;
};

// Dijoint Sets Union
void make_set(int parent[], int size[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int parent[], int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find(parent, parent[v]);
}

bool Union(int parent[], int size[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return false; // khong the gop a, b vao voi nhau
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}

bool compare(EDGE a, EDGE b)
{
    return a.w < b.w;
}

void kruskal(int parent[], int size[], vector<EDGE> canh, int n, int m)
{
    vector<EDGE> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), compare);

    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1) return;
        EDGE e = canh[i];
        if (Union(parent, size, e.x, e.y))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() != n - 1)
    {
        cout << "Do thi khong lien thong!\n";
    }
    else
    {
        cout << "MST: " << d << endl;
        for (auto it : mst)
        {
            cout << it.x << " " << it.y << " " << it.w << endl;
        }
    }

}

void prim(vector<pair<int, int>> adj[],int used[], int u, int n)
{
    vector<EDGE> mst;
    int d = 0;
    used[u] = true;
    while (mst.size() < n - 1)
    {
        int min_w = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
            {
                for (pair<int, int> it : adj[i])
                {
                    int j = it.first, trongso = it.second;
                    if (!used[j] && trongso < min_w)
                    {
                        min_w = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        mst.push_back({ X,Y,min_w });
        d += min_w;
        used[X] = true;
    }
    cout << d << endl;
    for (EDGE e : mst)
    {
        cout << e.x << " " << e.y << " " << e.w;
    }
}

void dinhtru(vector<vector<int>> matrix)
{
    vector<bool> visited(matrix.size(), false);
    int ans = 0;
    int soDinhTru = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (!visited[i])
        {
            ++ans;
            dfs(matrix, i, visited);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        visited.resize(matrix.size(), false);
        visited[i] = true;
        int dem = 0;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (!visited[j])
            {
                ++dem;
                dfs(matrix,j,visited);
            }
        }
        if (dem > ans)
        {
            cout << i << " ";
            ++soDinhTru;
        }
    }

}

vector<pair<int, int>> dsCanh(vector<vector<int>> matrix)
{
    vector<pair<int, int>> dscanh;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            dscanh.push_back({ i,j });
        }
    }
    return dscanh;
}

void dfs2(vector<vector<int>> matrix, int u, int s, int t, vector<bool>& visited)
{
    visited[u] = true;
    for (int i = 0; i < matrix[u].size(); i++)
    {
        if ((u == s && i == t) || (u == t && i == s)) continue;
        if (!visited[i]) dfs2(matrix, i, s, t, visited);
    }
}
void dfs3(vector<vector<int>> adj, int start, vector<bool>& visited)
{

    // Print the current node
    cout << start << " ";

    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    for (int i = 0; i < adj[start].size(); i++) {

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] == 1 && (!visited[i])) {
            dfs3(adj, i, visited);
        }
    }
}
void canhCau(vector<vector<int>> matrix)
{
    vector<bool>visited(matrix.size(), false);
    int ans = 0;
    int tplt = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (!visited[i])
        {
            ++tplt;
            dfs(matrix, i, visited);    
        }
    }
    vector<pair<int, int>> dscanh = dsCanh(matrix);
    for (auto it : dscanh)
    {
        int x = it.first; int y = it.second;
        visited.resize(matrix.size(), false);
        int dem = 0;
        for (int j = 0; j < matrix.size(); j++)
        {
            if (!visited[j])
            {
                dem++;
                dfs2(matrix, j, x, y, visited);
            }
        }
        if (dem > tplt)
        {
            ++ans;
            cout << x << " " << y << endl;
        }
    }
    cout << ans << endl;

}
int main()
{
    int size1, size2;
    vector<vector<int>> matrix1 = readAdjacencyMatrix("graph1.txt", size1);
    vector<vector<int>> matrix2 = readAdjacencyList("graph2.txt", size2);
    cout << size1 << endl;
    vector<bool> visited(size1, false);
    dfs(matrix1, 0, visited);
    //dfs3(matrix1, 0, visited);    
 /*   for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[i].size(); j++)
        {
            if (matrix2[i][0] != -1)
            {
                cout << matrix2[i][j] << " ";
            }
            
        }
        cout << endl;
    }*/
    //vector<vector<int> > matrix{
    //    {0, 1, 1, 1, 1},
    //    {1, 0, 1, 1, 1},
    //    {1, 1, 0, 1, 1},
    //    {1, 1, 1, 0, 1},
    //    {1, 1, 1, 1, 0}
    //};
    //for (int i = 0; i < 5; i++)
    //{
    //    for (int j = 0; j < 5; j++)
    //    {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << isCompleteGraph(matrix);
    

    
    
    /*for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] > 0)
            {
                cout << j << " ";
                count++;
            }
        }
        if (count == 0) cout << endl;
        cout << endl;
    }*/
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
