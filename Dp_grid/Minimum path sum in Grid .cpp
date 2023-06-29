class Solution
{
public:
    int calc(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        int ans = INT_MAX;
        if (i > 0)
            ans = min(ans, dp[i - 1][j]);
        if (i < n)
            ans = min(ans, dp[i + 1][j]);
        if (j > 0)
            ans = min(ans, dp[i][j - 1]);
        if (j < m)
            ans = min(ans, dp[i][j + 1]);
        return ans;
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (i == 0 and j == 0)
                    continue;
                dp[i][j] = grid[i][j] + calc(i, j, n, m, dp);
            }

        return dp[n - 1][m - 1];
    }
};

