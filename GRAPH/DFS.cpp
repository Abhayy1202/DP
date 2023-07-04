class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], int s, vector<bool> &visited, vector<int> &ans)
    {
        visited[s] = true;
        ans.push_back(s);
        for (auto u : adj[s])
        {
            if (visited[u] == false)
                dfs(adj, u, visited, ans);
        }
        return;
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                dfs(adj, i, visited, ans);
        }
        return ans;
    }
};