class Solution
{
public:
    void deg(vector<int> adj[], int &V, vector<int> &indegree)
    {
        for (int i = 0; i < V; i++)
        {
            for (int u : adj[i])
                indegree[u]++;
        }
    }
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0); // indegree of every edge
        deg(adj, V, indegree);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans;
    }
};