class Solution {
private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void fill_if_surrounded(vector<vector<char>>& board, vector<vector<bool>> visited, int row, int col) {
        //dfs until reach edge, if reach edge return.
        stack<pair<int, int>> dfs;
        dfs.push({row, col});

        //for (int i = 0; i < 5; i++) {
        while (!dfs.empty()) {
            pair top = dfs.top();
            dfs.pop();
            int r = top.first;
            int c = top.second;
            visited[r][c] = true;
            //touching edge; cannot be surrounded
            if (r == 0 || r == board.size() - 1 || c == 0 || c == board[0].size() - 1) return;

            for (auto& direction : dir) {
                int xdir = direction.first + r;
                int ydir = direction.second + c;

                if (xdir < 0 || xdir >= board.size() || ydir < 0 || ydir >= board[0].size()||
                    board[xdir][ydir] != 'O' || visited[xdir][ydir]) {
                    continue;
                } else {
                    dfs.push({xdir, ydir});
                }
            
            }
        }

        //if no edge, perform bfs on original index to flip everthing to X's.
        queue<pair<int, int>> bfs;
        bfs.push({row, col});
        while (!bfs.empty()) {
            pair top = bfs.front();
            bfs.pop();
            int r = top.first;
            int c = top.second;
            visited[r][c] = true;
            board[r][c] = 'X';
            for (auto& direction : dir) {
                int xdir = direction.first + r;
                int ydir = direction.second + c;

                if (xdir < 0 || xdir >= board.size() || ydir < 0 || ydir >= board[0].size()||
                    board[xdir][ydir] != 'O') {
                    continue;
                } else {
                    bfs.push({xdir, ydir});
                }
            
            }
        }

    }

public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    fill_if_surrounded(board, visited, i, j);
                }
            }
        }
    }
};
