class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid) 
        {
            vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
            queue<vector<int>> q;
            int time = 0;
            
            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (grid[i][j] == 2)
                    {
                        vector<int> temp(3);
                        temp[0] = i;
                        temp[1] = j;
                        temp[2] = 0;
                        q.push(temp);
                    }
                }
            }
            // ++time;
            while (!q.empty())
            {
                vector<int> curr = q.front();
                q.pop();
                vis[curr[0]][curr[1]] = true;
                time = curr[2];
                int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};
                for (int k = 0; k < 4; ++k)
                {
                    int r = curr[0]+dr[k], c = curr[1]+dc[k];
                    if (r<grid.size() && c<grid[0].size() && r>=0 && c>=0 && grid[r][c] == 1 && vis[r][c] == false)
                    {
                        vector<int> temp(3);
                        temp[0] = r;
                        temp[1] = c;
                        temp[2] = curr[2]+1;
                        q.push(temp);
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