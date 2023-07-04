class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V + 1, false);
        vector<int> ans;

        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (int v : adj[u])
            {
                if (visited[v] == false)
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return ans;
    }
};