class Solution 
{
public:
    
    void rotate(vector<vector<int>>& matrix) 
    {
        //transpose
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=i;j<matrix[i].size();++j)
                swap(matrix[i][j], matrix[j][i]);
        }
        
        //flip
        for(int i=0;i<matrix.size();++i)
        {
            int beg=0, end=matrix[i].size()-1;
            while(beg<=end)
            {
                swap(matrix[i][beg], matrix[i][end]);
                ++beg, --end;
            }
        }
    }
};