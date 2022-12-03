//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool detectCycle(int src, vector<int> adj[], vector<bool> vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push(make_pair(src, -1));
        while(!q.empty())
        {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            for (auto x: adj[node])
            {
                if (!vis[x])
                {
                    vis[x]=1;
                    q.push(make_pair(x, node));
                }
                else
                {
                    if (parent != x)
                        return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) 
    {
        // Code here
        vector<bool> vis(V, false);
        bool ans = false;
        for (int i=0; i<V; ++i)
        {
            ans = ans || detectCycle(i, adj, vis);
            if (ans)
                return true;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends