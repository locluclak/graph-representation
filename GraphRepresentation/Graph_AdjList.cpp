#include "Graph_AdjList.h"
#include "queue"
istream& operator>>(istream& m, Graph_AdjList& a)
{
	cout << "Nhap so dinh: ";
	m >> a.V;
	// Cap phat mang gom V (dinh) phan tu 
	a.G = new list<int>[a.V];

	int E;
	cout << "Nhap so canh: ";
	m >> E;
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		// Nhap canh giua v1 va v2
		m >> v1 >> v2;

		// Them canh v1-v2 vao do thi
		a.addEdge(v1, v2);
	}
	return m;
}
ostream& operator<<(ostream& m, const Graph_AdjList& a)
{
	m << "So dinh: " << a.V << endl;
	for (int i = 0; i < a.V; i++)
	{
		m << "Dinh ke " << i << ": ";
		for (auto neig = (a.G[i]).begin(); neig != (a.G[i]).end(); neig++)
		{
			m << *neig << " ";
		}
		cout << "\n";
	}
	return m;
}
void Graph_AdjList::addEdge(int _start, int _end)
{
	// Them dinh v2 vao G[v1] (Danh sach cac dinh ke v1) 
	(this->G[_start]).push_back(_end);
	//(this->G[_end]).push_back(_start); // if Graph is undirected
}
void Graph_AdjList::delEdge(int _start, int _end)
{
	G[_start].remove(_end);
}
bool Graph_AdjList::checkEdge(int _start, int _end)
{
	for (auto i = G[_start].begin(); i != G[_start].end(); i++)
		if (*i == _end) return true;
	return false;
}

void Graph_AdjList::DFS(int st, bool* visited)
{
	visited[st] = true;
	cout << "DFS duyet " << st << endl;
	for (auto neighbor = G[st].begin(); neighbor != G[st].end(); neighbor++)
	{
		if (!visited[*neighbor])
			DFS(*neighbor, visited);
	}
}

void Graph_AdjList::DFS(int _start)
{
	bool* visited = new bool[this->V];
	//initalize ele visited = false
	for (int i = 0; i < V; i++) visited[i] = false;
	DFS(_start, visited);

	delete[] visited;
}
void Graph_AdjList::BFS(int _start)
{
	bool* visited = new bool[this->V];
	//initalize ele visited = false
	for (int i = 0; i < V; i++) visited[i] = false;

	queue<int> q;
	q.push(_start);
	visited[_start] = true;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << "BFS duyet " << curr << endl;

		for (auto neighbor = G[curr].begin(); neighbor != G[curr].end(); neighbor++)
		if (!visited[*neighbor])
		{
			q.push(*neighbor);
			visited[*neighbor] = true;
		}
	}
	delete[] visited;
}