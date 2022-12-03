class Solution
{
    vector<vector < bool>> vis;
    bool isValid(pair<int, int> &p)
    {
        if (p.first < 0 || p.second < 0)
            return false;
        if (p.first >= vis.size() || p.second >= vis[0].size())
            return false;
        return true;
    }

    bool detect(pair<int, int> src, vector<vector< char>> &grid)
    {
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push(make_pair(src, make_pair(-1, -1)));
        char x = grid[src.first][src.second];
        vis[src.first][src.second] = true;
        while (!q.empty())
        {
            pair<int, int> curr = q.front().first, parent = q.front().second;
            q.pop();

            int dr[4] = { 0,
                0,
                -1,
                1
            }, dc[4] = { -1,
                1,
                0,
                0
            };

            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> neighbour = make_pair(curr.first + dr[i], curr.second + dc[i]);
                if (!isValid(neighbour) || grid[neighbour.first][neighbour.second] != x)
                    continue;
                if (!vis[neighbour.first][neighbour.second])
                {
                    vis[neighbour.first][neighbour.second] = true;
                    q.push(make_pair(neighbour, curr));
                }
                else
                {
                    if (parent != neighbour)
                        return true;
                }
            }
        }

        return false;
    }
    public:
        bool containsCycle(vector<vector < char>> &grid)
        {
            vis.resize(grid.size(), vector<bool> (grid[0].size(), false));
            for (int i = 0; i < grid.size(); ++i)
            {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                    if (!vis[i][j])
                    {
                        if (detect(make_pair(i, j), grid))
                            return true;
                    }
                }
            }

            return false;
        }
};