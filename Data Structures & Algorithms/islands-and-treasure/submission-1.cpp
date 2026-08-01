class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        int INF = 2147483647;

        //push all treasure chests in the queue
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j, 0});
                }
            }
        }

        int visited[rows][cols] = {0};
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0},{0, -1}};

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            visited[x][y] = 1;

            for (auto [dx, dy] : dir) {
                int nrow = dx + x;
                int ncol = dy + y;
                if (nrow < 0 || ncol < 0 || nrow >= rows || ncol >= cols || 
                    grid[nrow][ncol] != INF || visited[nrow][ncol] == 1) {
                    continue;
                }
                grid[nrow][ncol] = d + 1;
                q.push({nrow, ncol, d + 1});
            }
        }
    }
};

