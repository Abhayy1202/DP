class Solution
{
public:
    int mod = 1e9 + 7;
    int calc(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (n < 0 or m < 0)
            return 0;
        if (n == 0 and m == 0)
            return 1;
        if (grid[n][m] == 1)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = (calc(n - 1, m, grid, dp) + calc(n, m - 1, grid, dp)) % mod;
    }
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        // Code here
        if (grid[0][0] == 1 or grid[n - 1][m - 1] == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return (calc(n - 1, m - 1, grid, dp)) % mod;
    }
};