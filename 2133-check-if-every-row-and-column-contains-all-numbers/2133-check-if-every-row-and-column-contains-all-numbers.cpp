class Solution 
{
public:
    bool checkValid(vector<vector<int>>& matrix) 
    {
        for(int i=0;i<matrix.size();++i)
        {
            map<int, int> mrow, mcol;
            for(int j=0;j<matrix[i].size();++j)
            {
                ++mrow[matrix[i][j]];
                ++mcol[matrix[j][i]];
            }
            if(mrow.size()<matrix.size() || mcol.size()<matrix.size())
                return false;
            int k=1;
            for(auto it:mrow)
            {
                if(it.first!=k)
                    return false;
                ++k;
            }
            k=1;
            for(auto it:mcol)
            {
                if(it.first!=k)
                    return false;
                ++k;
            }
        }
        return true;
    }
};