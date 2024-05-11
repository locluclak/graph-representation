class Solution {
public:
    void DFS(const vector<vector<int>>& rooms, int id, vector<bool> &visited)
    {
        visited[id] = true;
        for (auto i: rooms[id])
        {
            if (!visited[i]) DFS(rooms, i, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        vector<bool> visited(n,false);
        DFS(rooms, 0, visited);
        for (auto i: visited)
            if (!i) return false;
        return true;

    }
};
