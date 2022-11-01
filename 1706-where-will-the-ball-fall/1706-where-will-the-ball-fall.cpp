class Solution
{
    int stuck(vector<vector < int>> &grid, int col)
    {
        int i = 0, j = col;
        // cout << "for " << col << "- ";
        while (i < grid.size() && j < grid[i].size() && j >= 0)
        {
            // cout << i << " " << j << "\n";
            int prevRow = i, prevCol = j;
            if (grid[i][j] == 1)
            {
                if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
                {
                    ++i, ++j;
                }
                else return -1;
            }
            else if (grid[i][j] == -1)
            {
                if (j - 1 >= 0 && grid[i][j - 1] == -1)
                {
                    ++i, --j;
                }
                else return -1;
            }
            if (prevRow >= i || prevCol == j)
                return -1;
        }
        // cout << i << j << "\n";
        if (i >= grid.size())
            return j;
        else return -1;
    }
    public:
        vector<int> findBall(vector<vector < int>> &grid)
        {
            vector<int> res(grid[0].size());
            for (int i = 0; i < grid[0].size(); ++i)
                res[i] = stuck(grid, i);

            return res;
        }
};