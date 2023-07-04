class Solution
{
public:
    void dfs(int index, vector<vector<int>> &adj, int V, vector<bool> &vis)
    {
        vis[index] = true;
        for (int j = 0; j < V; j++)
        {
            if (index != j && vis[j] == false && adj[index][j] == 1)
                dfs(j, adj, V, vis);
        }
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<bool> vis(V, false);
        int temp = 0;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == 0)
            {
                temp += 1;
                dfs(i, adj, V, vis);
            }
        }
        return temp;
    }
};