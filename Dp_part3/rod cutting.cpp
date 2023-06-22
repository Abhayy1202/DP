class Solution
{
public:
    int cutRod(int price[], int n)
    {
        // code here
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
            {
                dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
            }
        return dp[n];
    }
};