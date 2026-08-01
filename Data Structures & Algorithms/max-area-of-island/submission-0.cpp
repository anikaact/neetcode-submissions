class Solution {
public:
    int max = 0;
    int cur = 0;

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        cur = cur + 1;
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                cur = 0;
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    cout << cur;
                    if (cur > max) {
                        max = cur;
                    }
                }
            }
        }
        return max;
    }
};
