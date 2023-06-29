class Solution
{
public:
    int calc(int a, int b, vector<vector<int>> &dp)
    {
        if (a < 0 or b < 0)
            return 0;
        if (a == 0 and b == 0)
            return 1;
        if (dp[a][b] != -1)
            return dp[a][b];
        return dp[a][b] = calc(a - 1, b, dp) + calc(a, b - 1, dp);
    }
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        // code here
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

        return calc(a - 1, b - 1, dp);
    }
};