class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        grid[0][0] = -1;

        vector<pair<int, int>> directions = {
            {-1, 0}, {0, 1}, {0, -1}, {1, 0}
        };

        while(!pq.empty()) {
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1) return time;

            for(auto& [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != -1) {
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                    grid[nx][ny] = -1;
                }
            }
        }

        return -1;
    }
};
