class Solution
{
    public:
        vector<vector<int>> generate(int n)
        {
            vector<vector<int>> res(n);
            res[0].push_back(1);
            
            if (n == 1)
                return res;
            
            res[1].push_back(1);
            res[1].push_back(1);
            for (int i = 2; i < n; ++i)
            {
                res[i].resize(i + 1);
                res[i][0] = res[i][i] = 1;
                
                for (int j = 1; j < res[i].size() - 1; ++j)
                    res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            
            return res;
        }
};