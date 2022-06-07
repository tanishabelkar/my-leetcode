class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(),INT_MAX-1000));
        
        //top to down
        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[i].size();++j)
            {
                if(mat[i][j]==1)
                {
                    if(i>0)
                        res[i][j]=min(res[i][j], 1+res[i-1][j]);
                    if(j>0)
                        res[i][j]=min(res[i][j], 1+res[i][j-1]);
                }
                else res[i][j]=0;
            }
        }
        
        //bottom to up
        for(int i=mat.size()-1;i>=0;--i)
        {
            for(int j=mat[i].size()-1;j>=0;--j)
            {
                if(mat[i][j]==1)
                {
                    if(i<mat.size()-1)
                        res[i][j]=min(res[i][j], 1+res[i+1][j]);
                    if(j<mat[i].size()-1)
                        res[i][j]=min(res[i][j], 1+res[i][j+1]);
                }
                else res[i][j]=0;
            }
        }
        
        return res;
    }
};