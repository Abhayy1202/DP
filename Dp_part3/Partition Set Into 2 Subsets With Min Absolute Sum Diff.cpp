class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        if (n == 1)
            return arr[n - 1];
        int sum = accumulate(arr, arr + n, 0), ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        vector<int> v;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
        }

        for (int i = 0; i <= sum; i++)
        {
            if (dp[n][i] != 0)
            {
                int diff = abs(i - (sum - i));
                ans = min(ans, diff);
            }
        }
        return ans;
    }
};