class Solution
{
    vector<vector < int>> res, vis;
    void dfs(int i, int j, int newc, int oldc)
    {
        if (i >= 0 && i < res.size() && j >= 0 && j < res[0].size() && vis[i][j] == 0)
        {
            vis[i][j] = 1;
            if (res[i][j] == oldc)
            {
                res[i][j] = newc;
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
                    dfs(i + dr[k], j + dc[k], newc, oldc);
            }
        }
    }
    public:
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {
            res = image;
            vis.resize(image.size(), vector<int>(image[0].size(), 0));
            dfs(sr, sc, color, image[sr][sc]);
            return res;
        }
};