class Solution
{
public:
    int helper(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row, int col1, int col2, int n, int m)
    {
        if (row >= n or col1 < 0 or col2 < 0 or col1 >= m or col2 >= m)
            return 0;

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int ans = INT_MIN;
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
            {
                ans = max(ans, helper(grid, dp, row + 1, col1 + i, col2 + j, n, m));
            }

        if (col1 == col2)
            dp[row][col1][col2] = ans + grid[row][col1];
        else
            dp[row][col1][col2] = ans + grid[row][col1] + grid[row][col2];

        return dp[row][col1][col2];
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(grid, dp, 0, 0, m - 1, n, m);
    }
};