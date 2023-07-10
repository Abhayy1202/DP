class Solution
{
public:
    void dfs(vector<vector<int>> &visited, vector<vector<int>> &grid, int row, int col, int dx[], int dy[], int &b_row, int &b_col, vector<pair<int, int>> &v)
    {
        int n = grid.size(), m = grid[0].size();
        visited[row][col] = 1;
        v.push_back({row - b_row, col - b_col});

        for (int k = 0; k < 4; ++k)
        {
            int new_row = row + dx[k], new_col = col + dy[k];
            if (new_row >= 0 and new_col >= 0 and new_row < n and new_col < m and grid[new_row][new_col] == 1 and !visited[new_row][new_col])
            {
                dfs(visited, grid, new_row, new_col, dx, dy, b_row, b_col, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        set<vector<pair<int, int>>> s;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] and grid[i][j] == 1)
                {
                    vector<pair<int, int>> v;
                    dfs(visited, grid, i, j, dx, dy, i, j, v);
                    if (!v.empty())
                        s.insert(v);
                }
            }
        return s.size();
    }
};