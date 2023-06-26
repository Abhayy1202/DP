
class Solution
{
public:
    int maxProfit(int K, int n, int A[])
    {
        // code here

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(K, 0)));
        for (int i = n - 1; i >= 0; i--)
            for (int buy = 0; buy < 2; buy++)
                for (int count = 0; count < K; count++)
                {
                    if (buy == 0)
                        dp[i][buy][count] = max(dp[i + 1][0][count], dp[i + 1][1][count] - A[i]);
                    else
                        dp[i][buy][count] = max(dp[i + 1][1][count], dp[i + 1][0][count - 1] + A[i]);
                }
        return dp[0][0][K - 1];
    }
};