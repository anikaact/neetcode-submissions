class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>> rotten;
        int rows = grid.size();
        int cols = grid[0].size();
        int mins = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j, 0});
                }
            }
        }

        int visited[rows][cols] = {0};
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 

        while (!rotten.empty()) {
            auto [x, y, m] = rotten.front();
            mins = m;
            rotten.pop();

            for (auto [dx, dy] : dir) {
                int nrow = dx + x;
                int ncol = dy + y;

                if (nrow < 0 || ncol < 0 || nrow >= rows || ncol >= cols || visited[nrow][ncol] == 1
                    || grid[nrow][ncol] != 1) {
                        continue;
                }

                grid[nrow][ncol] = 2;
                rotten.push({nrow, ncol, m + 1});
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return mins;
    }
};
