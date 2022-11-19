//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
            return;
        if (grid[r][c] != '1')
            return;
        grid[r][c] = '*';
        int dr[8] = {-1, 1, 0, 0, 1, -1, -1, 1}, dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        
        for (int i = 0; i < 8; ++i)
        {
            dfs(grid, r+dr[i], c+dc[i]);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        int ans = 0;
        //vis.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    // cout << i << " "<<j<<"\n";
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends