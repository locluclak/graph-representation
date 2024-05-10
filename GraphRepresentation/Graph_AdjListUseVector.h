#include "iostream"
#include "vector"
using namespace std;
#pragma once
class Graph_AdjListUseVector
{
private:
	int V;
	vector<vector<int>> G;
public:
	friend istream& operator>>(istream&, Graph_AdjListUseVector&);
	friend ostream& operator<<(ostream&, const Graph_AdjListUseVector&);
	void addEdge(int _start, int _end);
	void delEdge(int _start, int _end);
	bool checkEdge(int _start, int _end);
	void DFS(int _start);
	void BFS(int _end);
};



