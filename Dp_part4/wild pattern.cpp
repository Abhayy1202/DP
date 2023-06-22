class Solution
{
public:
    bool helper(string &S1, int i)
    {

        for (int j = 1; j <= i; j++)
        {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }
    int wildCard(string pattern, string str)
    {
        int n = pattern.size(), m = str.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = helper(pattern, i);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (pattern[i - 1] == str[j - 1] or pattern[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else
                {
                    if (pattern[i - 1] == '*')
                        dp[i][j] = dp[i][j - 1] or dp[i - 1][j];
                    else
                        dp[i][j] = false;
                }
            }
        return dp[n][m];
    }
};