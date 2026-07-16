class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        const int INF = INT_MAX, m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0) q.emplace(i, j);

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && rooms[ni][nj] == INF) {
                    rooms[ni][nj] = rooms[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }
    }
};
