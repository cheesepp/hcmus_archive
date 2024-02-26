#include "Graph.h"

void Graph::input()
{
	int n;
	cout << "Nhap so dinh: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap so canh ke voi dinh " << i << ": ";
		int numOfEdges;
		cin >> numOfEdges;
		vertices.push_back(i);
		vector<int> temp;
		for (int j = 0; j < numOfEdges; j++) {
			int n;
			cin >> n;
			temp.push_back(n);

		}
		adjList.push_back(temp);
	}
}

void Graph::output()
{
	cout << "Ma tran ke:\n";
	for (int i = 0; i < adjList.size(); i++) {
		cout << i << " | ";
		for (int j = 0; j < adjList[i].size(); j++) {
			cout << adjList[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::bfs() {
	int start;
	cout << "Nhap diem bat dau: ";
	cin >> start;
	vector<int> mark(vertices.size());
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		mark[y] = 1;
		cout << y << " ";
		for (int z : adjList[y]) {
			if (!mark[z]) {
				q.push(z);
			}
		}
	}
}