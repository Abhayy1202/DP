class Solution
{
public:
    int helper(string s1, string s2, int n, int m)
    {
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return curr[m];
    }
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        // code here
        return m + n - helper(X, Y, m, n);
    }
};