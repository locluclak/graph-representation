#include "iostream"
#include "list"
using namespace std;
#pragma once
class Graph_AdjList
{
private:
	int V;
	list<int> *G;
public:
	friend istream& operator>>(istream&, Graph_AdjList&);
	friend ostream& operator<<(ostream&, const Graph_AdjList&);
	void addEdge(int _start, int _end);
	void delEdge(int _start, int _end);
	bool checkEdge(int _start, int _end);
	void DFS(int st, bool* visited);
	void DFS(int _start);
	void BFS(int _end);
};


