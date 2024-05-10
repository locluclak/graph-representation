#include "Graph_AdjMatrix.h"
#include "queue"

Graph_AdjMatrix::Graph_AdjMatrix()
{
	V = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
		{
			if (i == j) this->G[i][j] = 1;
			else this->G[i][j] = 0;
		}
}
istream& operator>>(istream& m, Graph_AdjMatrix& a)
{
	cout << "Nhap so dinh: ";
	m >> a.V;
	int E;
	cout << "Nhap so canh: ";
	m >> E;
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		m >> v1 >> v2;
		a.addEdge(v1, v2);
	}
	return m;
}
ostream& operator<<(ostream& m, const Graph_AdjMatrix& a)
{
	m << "So dinh: " << a.V << endl;
	for (int i = 0; i < a.V; i++)
	{
		for (int j = 0; j < a.V; j++)
			m << a.G[i][j] << ' ';
		m << endl;
	}
	return m;
}
void Graph_AdjMatrix::addEdge(int _start, int _end)
{
	this->G[_start][_end] = 1;
	//this->G[_end][_start] = 1; // if Graph is undirected
}
void Graph_AdjMatrix::delEdge(int _start, int _end)
{
	this->G[_start][_end] = 0;
	//this->G[_end][_start] = 0; // if Graph is undirected
}
bool Graph_AdjMatrix::checkEdge(int _start, int _end) const
{
	return this->G[_start][_end];
}

void Graph_AdjMatrix::DFS(int st, bool *visited)
{
	visited[st] = true;
	cout << "DFS duyet " << st << endl;
	for (int neighbor = 0; neighbor < V; neighbor++)
	{
		if (!visited[neighbor] && G[st][neighbor])
			DFS(neighbor, visited);
	}
}


void Graph_AdjMatrix::DFS(int _start)
{
	bool* visited = new bool[this->V];
	//initalize ele visited = false
	for (int i = 0; i < V; i++) visited[i] = false;
	DFS(_start, visited);
	delete[] visited;
}

void Graph_AdjMatrix::BFS(int _start)
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

		
		for (int neighbor = 0; neighbor < V; neighbor++)
		{
			if (!visited[neighbor] && G[curr][neighbor])
			{
				q.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
	delete[] visited;
}
//--Duong Tan Loc UIT--