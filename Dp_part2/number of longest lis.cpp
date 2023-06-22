class Solution{
    public :
        int NumberofLIS(int n, vector<int> &a){
            // Code here
            int len = 1;
int ans = 0;
vector<int> v(n, 1), count(n, 1);

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < i; j++)
    {
        if (a[i] > a[j] and v[i] <= 1 + v[j])
            if (v[i] == v[j] + 1)
                count[i] += count[j];

            else
            {
                v[i] = max(v[i], v[j] + 1);
                count[i] = count[j];
            }
    }
    len = max(len, v[i]);
}
for (int i = 0; i < n; i++)
{
    if (len == v[i])
        ans += count[i];
}
return ans;
}
};