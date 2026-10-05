class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<int>>& grid, int& zero, int& ans) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return;

        if (grid[r][c] == -1)
            return;

        if (grid[r][c] == 2) {
            if (zero == 0)
                ans++;
            return;
        }

        bool isZero = (grid[r][c] == 0);

        grid[r][c] = -1;

        if (isZero)
            zero--;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            dfs(nr, nc, grid, zero, ans);
        }

        if (isZero) {
            grid[r][c] = 0;
            zero++;
        } else {
            grid[r][c] = 1;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sr = -1;
        int sc = -1;
        int zero = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    zero++;
                } else if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
            }
        }

        dfs(sr, sc, grid, zero, ans);

        return ans;
    }
};
