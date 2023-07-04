class Solution
{
public:
    void dfs(int &n, int &m, vector<vector<int>> &image, int i, int j, int &nc, int &val, vector<vector<int>> &dp)
    {
        if (i - 1 >= 0 and image[i - 1][j] == val and dp[i - 1][j] != nc)
        {
            dp[i - 1][j] = nc;
            dfs(n, m, image, i - 1, j, nc, val, dp);
        }
        if (i + 1 < n and image[i + 1][j] == val and dp[i + 1][j] != nc)
        {
            dp[i + 1][j] = nc;
            dfs(n, m, image, i + 1, j, nc, val, dp);
        }
        if (j - 1 >= 0 and image[i][j - 1] == val and dp[i][j - 1] != nc)
        {
            dp[i][j - 1] = nc;
            dfs(n, m, image, i, j - 1, nc, val, dp);
        }
        if (j + 1 < m and image[i][j + 1] == val and dp[i][j + 1] != nc)
        {
            dp[i][j + 1] = nc;
            dfs(n, m, image, i, j + 1, nc, val, dp);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int nc)
    {
        // Code here
        int n = image.size(), m = image[0].size();
        vector<vector<int>> dp;
        dp = image;
        int val = image[sr][sc];
        dp[sr][sc] = nc;
        dfs(n, m, image, sr, sc, nc, val, dp);
        return dp;
    }
};
