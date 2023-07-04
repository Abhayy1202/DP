class Solution
{

public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size(), m = grid[0].size(), ans = 0, total = 0, count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                    total++;

                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (!q.empty())
        {
            int curr = q.size();
            count += curr;
            while (curr--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();

                if (i - 1 >= 0 and grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    q.push({i - 1, j});
                }
                if (i + 1 < n and grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
                if (j - 1 >= 0 and grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    q.push({i, j - 1});
                }
                if (j + 1 < m and grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    q.push({i, j + 1});
                }
            }
            if (!q.empty())
                ans++;
        }
        if (count == total)
            return ans;
        else
            return -1;
    }
};