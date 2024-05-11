#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int savedHouse(const vector<vector<bool>>& G, int j)
{
    int n = G.size();
    vector<bool> burned(n, false);
    queue<int> q;
    q.push(j);
    burned[j] = true;
    int nf = 1;
    int temp =0;
    int sol = nf;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        nf--;

        for (int i = 0; i < n; i++)
        {
            if (G[curr][i] && !burned[i])
            {
                q.push(i);
                burned[i] = true;
                temp++;
            }
        }
        if (nf == 0)
        {
            nf = temp;
            sol = (nf!=0) ? nf : sol;
            temp = 0;

        }
    }
    return sol;
}

int main()
{
    int n, e, j;
    cin >> n >> e >> j;
    vector<vector<bool>> G(n, vector<bool>(n, false));

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = true;
        G[v2][v1] = true;
    }
    cout << savedHouse(G, j);
    return 0;
}
