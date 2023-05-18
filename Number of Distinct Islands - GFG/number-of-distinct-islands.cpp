//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution 
{
    set<vector<pair<int, int>>> s;
    void dfs(vector<vector<int>> &grid, int basei, int basej, int i, int j, vector<pair<int, int>> &island)
    {
        island.push_back(make_pair(i - basei, j - basej));
        grid[i][j] = 0;
        int row[]={1, 0, -1, 0}, col[]={0, 1, 0, -1};
        for (int x = 0; x < 4; ++x)
        {
            int ni = i + row[x], nj = j + col[x];
            if (ni >= 0 && nj >= 0 && ni< grid.size() && nj<grid[0].size() && grid[ni][nj] == 1)
                dfs(grid, basei, basej, ni, nj, island);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
        // code here
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    vector<pair<int, int>> island;
                    dfs(grid, i, j, i, j, island);
                    s.insert(island);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends