class Solution
{
public:
    void dfs(vector<vector<bool>> &visited, vector<vector<char>> &mat, int row, int col, vector<int> &dx, vector<int> &dy)
    {
        int n = mat.size(), m = mat[0].size();
        visited[row][col] = true;
        for (int k = 0; k < 4; ++k)
        {
            int new_row = row + dx[k], new_col = col + dy[k];
            if (new_row >= 0 and new_col >= 0 and new_row < n and new_col < m and mat[new_row][new_col] == 'O' and !visited[new_row][new_col])
                dfs(visited, mat, new_row, new_col, dx, dy);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<char>> dp(n, vector<char>(m, 0));
        dp = mat;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O' and !visited[0][i])
                dfs(visited, mat, 0, i, dx, dy);
            if (mat[n - 1][i] == 'O' and !visited[n - 1][i])
                dfs(visited, mat, n - 1, i, dx, dy);
        }

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' and !visited[i][0])
                dfs(visited, mat, i, 0, dx, dy);
            if (mat[i][m - 1] == 'O' and !visited[i][m - 1])
                dfs(visited, mat, i, m - 1, dx, dy);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (!visited[i][j] and mat[i][j] == 'O')
                    dp[i][j] = 'X';
        }
        return dp;
    }
};