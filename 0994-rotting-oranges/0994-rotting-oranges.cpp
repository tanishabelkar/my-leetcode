class Solution
{
    vector<int> makevec(int i, int j, int k)
    {
        vector<int> temp(3);
        temp[0] = i;
        temp[1] = j;
        temp[2] = k;
        return temp;
    }
    bool isValid(vector<vector<int>> &grid, int r, int c)
    {
        return r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0;
    }
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            vector<vector < bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
            queue<vector < int>> q;
            int time = 0;

            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (grid[i][j] == 2)
                        q.push(makevec(i, j, 0));
                }
            }
           	// ++time;
            while (!q.empty())
            {
                vector<int> curr = q.front();
                q.pop();
                vis[curr[0]][curr[1]] = true;
                time = curr[2];
                int dr[4] = { 0,
                    -1,
                    0,
                    1
                }, dc[4] = { -1,
                    0,
                    1,
                    0
                };
                for (int k = 0; k < 4; ++k)
                {
                    int r = curr[0] + dr[k], c = curr[1] + dc[k];
                    if (isValid(grid, r, c) && grid[r][c] == 1 && vis[r][c] == false)
                    {
                        q.push(makevec(r, c, curr[2]+1));
                        vis[r][c] = true;
                    }
                }

               	// cout << curr[0] << curr[1] << curr[2]<< "\n";
            }

            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (grid[i][j] == 1 && vis[i][j] == false)
                        return -1;
                }
            }

            return time;
        }
};