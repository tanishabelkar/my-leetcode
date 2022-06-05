class Solution 
{
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int ans=0, n=mat.size();
        for(int i=0;i<mat.size();++i)
        {
            ans+=(mat[i][i]+mat[i][n-i-1]);
        }
        if(n&1)
            ans-=mat[n/2][n/2];
        return ans;
    }
};