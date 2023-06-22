class Solution{
    public :
//         bool help(string a, string b){
//             if (a.size() == b.size()) return a < b;
// return a.size() < b.size();
// }
bool check(string s1, string s2)
{
    if (s1.size() - s2.size() != 1)
        return false;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        string temp = s1;
        temp.erase(i, 1);
        if (temp == s2)
            return true;
    }
    return false;
}

int longestChain(int n, vector<string> &words)
{
    // Code here

    if (n == 1)
        return n;

    sort(words.begin(), words.end(), [&](string a, string b) -> bool
         {
            if(a.size() == b.size())
                return a < b;
            return a.size() < b.size(); });
    // sort(words.begin(), words.end(),help);

    vector<int> dp(n, 1);
    int len = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (check(words[i], words[j]))
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        len = max(len, dp[i]);
    }
    return len;
}
}
;