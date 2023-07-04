class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int na = row + dx[k];
                int nb = col + dy[k];
                if (na < 0 || nb < 0 || na >= n || nb >= m || dp[na][nb] != -1)
                    continue;
                q.push({na, nb});
                dp[na][nb] = dp[row][col] + 1;
            }
        }

        return dp;
    }
};