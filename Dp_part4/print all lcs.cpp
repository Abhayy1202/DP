//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void lcs(string s, string t, int n, int m, int len, string &f, vector<string> &ans, vector<vector<int>> &dp, unordered_set<string> &sols,vector<vector<int>>&memo)   //Not able to optimize this function using memoization
    {
        if (len == 0)
        {
            if (sols.count(f) == 0) // Check if f has not been generated before
            {
                string temp = f;
                reverse(temp.begin(), temp.end());
                ans.emplace_back(temp);
                sols.insert(f);
            }
            return;
        }
        if (n == 0 || m == 0)
        {
            return;
        }
        if (memo[n][m] == 1)
        {
            return;
        }
        else
        {
            memo[n][m] = 1;
        }
        if (s[n - 1] == t[m - 1])
        {
            f += s[n - 1];
            lcs(s, t, n - 1, m - 1, len - 1, f, ans, dp, sols,memo);
            f.pop_back();
        }
        else
        {
            if (dp[n - 1][m] > dp[n][m - 1])
            {
                lcs(s, t, n - 1, m, len, f, ans, dp, sols,memo);
            }
            else if (dp[n - 1][m] < dp[n][m - 1])
            {
                lcs(s, t, n, m - 1, len, f, ans, dp, sols,memo);
            }
            else
            {
                lcs(s, t, n - 1, m, len, f, ans, dp, sols,memo);
                lcs(s, t, n, m - 1, len, f, ans, dp, sols,memo);
            }
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        // Code here
        int len = 0, x = s.size(), y = t.size();
        vector<string> ans;
        string f = "";
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, 0));
        unordered_set<string> sols;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        len = dp[x][y];
        lcs(s, t, x, y, len, f, ans, dp, sols,memo);
        sort(ans.begin(), ans.end());
        return ans;
    }
    // int indx=len-1;
    // string f="";
    // for(int i=0;i<=indx;i++)
    // f+="$";

    // while(x>0 and y>0)
    // {
    // if(s[x-1]==t[y-1])
    // {
    //     f[indx]=s[x-1];
    //     indx--;x--;y--;
    // }
    // else if(dp[x-1][y]>dp[x][y-1])
    // x--;
    // else y--;

    // }
    // ans.push_back(f);
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends