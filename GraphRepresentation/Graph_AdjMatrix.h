#include "iostream"
using namespace std;
#pragma once
class Graph_AdjMatrix
{
private:
	int V;
	int G[100][100];
public:
	Graph_AdjMatrix();
	friend istream& operator>>(istream&, Graph_AdjMatrix&);
	friend ostream& operator<<(ostream&, const Graph_AdjMatrix&);
	void addEdge(int _start, int _end);
	void delEdge(int _start, int _end);
	bool checkEdge(int _start, int _end) const;
	void DFS(int st, bool* visited);
	void DFS(int _start);
	void BFS(int _start);
};

//--Duong Tan Loc UIT--
