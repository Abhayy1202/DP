class Solution
{

public:
    int perfectSum(int ar[], int n, int sum)
    {
        // Your code goes here
        vector<int> arr;
        int mod = 1e9 + 7;
        int k = 0, zero = 1;                    
        for (int i = 0; i < n; i++)
        {
            if (ar[i] != 0)
                arr.push_back(ar[i]), k++;       //creating new array without zeros
            else
                zero = (zero * 2) % mod;        // option for zero as element is twice bcz it can be taken or not both
        }
        n = k;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j] % mod;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
        }
        dp[n][sum] = (dp[n][sum] * zero) % mod; 

        return dp[n][sum];

    }
};
        //   O(n) space approach
        //     vector <int> dp(sum+1);
        // int mod = 1e9+7;
        // dp[0] = 1;
        // for(int i = 1;i < n+1;i++){
        //     vector <int> t = dp;
        //     for(int j = 0;j < sum+1;j++)
        //         if(arr[i-1] <= j) t[j] = (t[j]+dp[j-arr[i-1]])%mod;
        //     dp = t;
        // }
        // return dp[sum];