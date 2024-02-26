#pragma once
#include<iostream>
#include <vector>
#include<queue>
using namespace std;
class Graph
{
private:
	vector<int> vertices;
	vector<vector<int>> adjList;
public:
	void input();
	void output();
	void bfs();
 
};

