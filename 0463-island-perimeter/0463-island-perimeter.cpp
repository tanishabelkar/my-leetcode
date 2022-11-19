class Solution
{
    int ans;
    vector<int> dr, dc;
    void help(vector<vector < int>> &grid, int r, int c)
    {
        // cout << "helping " << r << " " << c << "\n";
        if (grid[r][c] == 0 || grid[r][c] == -1)
            return;
        grid[r][c] = -1;
        for (int i = 0; i < 4; ++i)
        {
            if (r + dr[i] < 0 || r + dr[i] >= grid.size() || c + dc[i] < 0 || c + dc[i] >= grid[0].size() || grid[r + dr[i]][c + dc[i]] == 0)
            {
                ++ans;
                continue;
            }
            else
                help(grid, r + dr[i], c + dc[i]);
        }
    }
    public:
        Solution()
        {
            ans = 0;
            dr.resize(4, 0);
            dc.resize(4, 0);
            dr[0] = dc[2] = -1;
            dr[1] = dc[3] = 1;
        }
    int islandPerimeter(vector<vector < int>> &grid)
    {
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    help(grid, i, j);
                    break;
                }
            }
        }
        return ans;
    }
};