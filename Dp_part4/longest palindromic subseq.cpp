class Solution
{
public:
    int lcs(string a, string b, int n)
    {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        int len = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i - 1] == b[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        return curr[n];
    }

    int longestPalinSubseq(string A)
    {
        // code here
        int n = A.size();
        string B = A;
        reverse(A.begin(), A.end());
        return lcs(B, A, n);
    }
};