class Solution
{
public:
    bool dfs(int s, int curr_stat, vector<int> &visited, vector<int> adj[])
    {
        visited[s] = curr_stat;

        for (auto u : adj[s])
        {
            if (visited[u] == -1)
            {
                if (dfs(u, !curr_stat, visited, adj) == false)
                    return false;
            }
            else if (visited[u] == curr_stat)
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == -1)
                if (dfs(i, 0, visited, adj) == false)
                    return false;
        }
        return true;
    }
};