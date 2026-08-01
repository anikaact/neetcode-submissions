class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        //base case: out of bounds or water
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return islands;
    }
};
