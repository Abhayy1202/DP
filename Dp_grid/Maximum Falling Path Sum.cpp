class Solution
{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        if (n == 1)
            return matrix[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j + 1]);
                else if (j == n - 1)
                    matrix[i][j] += max(matrix[i - 1][j], matrix[i - 1][j - 1]);
                else
                    matrix[i][j] += max(matrix[i - 1][j + 1], max(matrix[i - 1][j], matrix[i - 1][j - 1]));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, matrix[n - 1][i]);
        return ans;
    }
};