//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    vector<int> color;
    bool safe(bool graph[101][101], int n, int curr, int col)
    {
        for (int i = 0; i < n; ++i)
        {
            if (graph[curr][i] == true && color[i] == col)
                return false;
        }
        return true;
    }
    bool solve(bool graph[101][101], int m, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            {
                for (int j = 1; j <= m; ++j)
                {
                    if (safe(graph, n, i, j))
                    {
                        color[i] = j;
                        if (solve(graph, m, n)) return true;
                        color[i] = -1;
                    }
                }
                return false;
            }
        }
        
        return true;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        color.resize(n, -1);
        return solve(graph, m, n);
    }
};

/*

0->1->2->3
^-----|--|
*/

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends