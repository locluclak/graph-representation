#include "Graph_AdjMatrix.h"
#include "Graph_AdjList.h"
int main()
{
	Graph_AdjList a;
	cin >> a;
	cout << a;
	a.BFS(0);
	a.DFS(0);
	return 0;
}