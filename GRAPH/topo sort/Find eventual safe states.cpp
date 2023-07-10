class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &rec_st, vector<bool> &is_safe, int s)
    {
        if (is_safe[s] == false)
            return false;
        visited[s] = true;
        rec_st[s] = true;
        for (auto v : adj[s])
        {
            if (!visited[v] and (dfs(adj, visited, rec_st, is_safe, v) == true))
            {
                is_safe[v] = false;
                return true;
            }
            else if (rec_st[v] == true)
            {
                is_safe[v] = false;
                return true;
            }
        }
        rec_st[s] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &adj)
    {
        // code here
        int V = adj.size();
        vector<int> v;
        vector<bool> visited(V, false), rec_st(V, false), is_safe(V, true);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] and (dfs(adj, visited, rec_st, is_safe, i) == true))
                is_safe[i] = false;
        }
        for (int i = 0; i < V; i++)
            if (is_safe[i] == true)
                v.push_back(i);
        return v;
    }
};