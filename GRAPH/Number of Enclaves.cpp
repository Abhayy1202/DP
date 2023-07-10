class Solution
{
public:
    void dfs(vector<vector<bool>> &visited, vector<vector<int>> &grid, int row, int col, vector<int> &dx, vector<int> &dy)
    {
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = true;
        for (int k = 0; k < 4; ++k)
        {
            int nx = row + dx[k], ny = col + dy[k];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1 and !visited[nx][ny])
                dfs(visited,grid, nx, ny, dx, dy);
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j] and grid[0][j] == 1)
                dfs(visited, grid, 0, j, dx, dy);
            if (!visited[n - 1][j] and grid[n - 1][j] == 1)
                dfs(visited, grid, n - 1, j, dx, dy);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0] and grid[i][0] == 1)
                dfs(visited, grid, i, 0, dx, dy);
            if (!visited[i][m - 1] and grid[i][m - 1] == 1)
                dfs(visited, grid, i, m - 1, dx, dy);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!visited[i][j] and grid[i][j] == 1)
                    count++;
        return count;
    }
};