//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    vector<vector<bool>> vis;
    void backtrack(vector<vector<int>> &grid, int r, int c, string path)
    {
        if (r == grid.size() - 1 && c == grid.size() - 1)
            ans.push_back(path);
        
        // move up
        if (r - 1 >= 0 && !vis[r - 1][c] && grid[r - 1][c] == 1)
        {
            path.push_back('U');
            vis[r - 1][c] = true;
            backtrack(grid, r - 1, c, path);
            path.pop_back();
            vis[r - 1][c] = false;
        }
        // move down
        if (r + 1 < grid.size() && !vis[r + 1][c] && grid[r + 1][c] == 1)
        {
            path.push_back('D');
            vis[r + 1][c] = true;
            backtrack(grid, r + 1, c, path);
            path.pop_back();
            vis[r + 1][c] = false;
        }
        // move left
        if (c - 1 >= 0 && !vis[r][c - 1] && grid[r][c - 1] == 1)
        {
            path.push_back('L');
            vis[r][c - 1] = true;
            backtrack(grid, r, c - 1, path);
            path.pop_back();
            vis[r][c - 1] = false;
        }
        // move right
        if (c + 1 < grid.size() && !vis[r][c + 1] && grid[r][c + 1] == 1)
        {
            path.push_back('R');
            vis[r][c + 1] = true;
            backtrack(grid, r, c + 1, path);
            path.pop_back();
            vis[r][c + 1] = false;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vis.resize(n, vector<bool>(n, false));
        vis[0][0] = true;
        if (m[0][0] == 0)
            return vector<string>(1, "-1");
        backtrack(m, 0, 0, "");
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends