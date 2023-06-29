class Solution
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        // Code here
        vector<vector<int>> ans(n, vector<int>(3, 0));
        ans[0][0] = points[0][0];
        ans[0][1] = points[0][1];
        ans[0][2] = points[0][2];

        for (int i = 1; i < n; i++)
        {
            ans[i][0] = max(ans[i - 1][1], ans[i - 1][2]) + points[i][0];
            ans[i][1] = max(ans[i - 1][0], ans[i - 1][2]) + points[i][1];
            ans[i][2] = max(ans[i - 1][1], ans[i - 1][0]) + points[i][2];
        }
        return max(ans[n - 1][0], max(ans[n - 1][1], ans[n - 1][2]));
    }
};