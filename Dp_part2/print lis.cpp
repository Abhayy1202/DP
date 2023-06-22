class Solution{
    public :
        vector<int>
            longestIncreasingSubsequence(int n, vector<int> &arr){
                // Code here
                vector<int> dp(n, 1), ans(n), temp;
for (int i = 0; i < n; i++)
{
    ans[i] = i;
    for (int j = 0; j < i; j++)
    {
        if (arr[j] < arr[i] and 1 + dp[j] > dp[i])
        {
          
            ans[i] = j;
            dp[i] = 1 + dp[j];
        }
    }
}
int len = 0, last_indx = 0;
for (int i = 0; i < n; i++)
{
    if (dp[i] > len)
    {
        len = dp[i];
        last_indx = i;
    }
}
temp.push_back(arr[last_indx]);
while (len - 1)
{
    int next_indx = ans[last_indx];
    temp.push_back(arr[next_indx]);
    last_indx = next_indx;
    len--;
}
reverse(temp.begin(), temp.end());
return temp;
}
}
;