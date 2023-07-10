class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pr)
    {
        // code here
        vector<int> indegree(n, 0), v;
        vector<vector<int>> adj(n);
        queue<int> q;
        for (int i = 0; i < m; i++)
            adj[pr[i][1]].push_back(pr[i][0]);

        for (int i = 0; i < n; i++)
            for (auto u : adj[i])
            {
                indegree[u]++;
            }

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            v.push_back(u);
            q.pop();

            for (auto k : adj[u])
            {
                indegree[k]--;
                if (indegree[k] == 0)
                    q.push(k);
            }
        }

        if (v.size() < n)
            return {};
        return v;
    }
};