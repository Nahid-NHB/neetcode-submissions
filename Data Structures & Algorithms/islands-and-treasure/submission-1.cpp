class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        const int INF = INT_MAX, m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (rooms[i][j] == 0) q.emplace(i, j);

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {  // Iterate over the 2D array
                int ni = i + directions[d][0], nj = j + directions[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && rooms[ni][nj] == INF) {
                    rooms[ni][nj] = rooms[i][j] + 1;
                    q.emplace(ni, nj);
                }
            }
        }
    }
};
