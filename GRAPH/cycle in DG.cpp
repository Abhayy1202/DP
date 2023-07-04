class Solution
{
public:
    // Function to detect cycle in a directed graph.
    void deg(vector<int> adj[], int V, vector<int> &indegree)
    {
        for (int i = 0; i < V; i++)
        {
            for (int u : adj[i])
                indegree[u]++;
        }
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0);
        deg(adj, V, indegree);
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
            count++;
        }
        return (count != V);
    }
};