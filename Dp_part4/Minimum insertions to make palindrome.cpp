class Solution
{
public:
    int helper(string s1, string s2, int n)
    {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
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
        return n - curr[n];
    }
    int countMin(string str)
    {
        // complete the function here
        if (str.size() == 1)
            return 0;
        string tmp = str;
        reverse(str.begin(), str.end());
        return helper(str, tmp, str.size());
    }
};