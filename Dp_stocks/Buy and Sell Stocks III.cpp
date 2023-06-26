int maxProfit(vector<int> &price)
{
    // Write your code here..vec
    int n = price.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    for (int i = n - 1; i >= 0; i--)
        for (int buy = 0; buy < 2; buy++)
            for (int count = 0; count < 2; count++)
            {
                if (buy == 0)
                    dp[i][buy][count] = max(dp[i + 1][0][count], dp[i + 1][1][count] - price[i]);
                else
                    dp[i][buy][count] = max(dp[i + 1][1][count], dp[i + 1][0][count - 1] + price[i]);
            }
    return dp[0][0][1];
}