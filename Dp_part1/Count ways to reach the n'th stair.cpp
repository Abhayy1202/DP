class Solution
{
public:
    // Function to count number of ways to reach the nth stair.

    int countWays(int n)
    {
        // your code here
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }

        return dp[n];
    }
};