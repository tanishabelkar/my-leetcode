class Solution 
{
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp(triangle.size());
        for(int i=0;i<dp.size();++i)
            dp[i].resize(triangle[i].size());
        dp[0][0]=triangle[0][0];
        for(int i=1;i<triangle.size();++i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                dp[i][j]=triangle[i][j];
                if(j==0)
                    dp[i][j]+=dp[i-1][j];
                else if(j>i-1)
                    dp[i][j]+=dp[i-1][j-1];
                else dp[i][j]+=min(dp[i-1][j], dp[i-1][j-1]);
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return *min_element(dp[triangle.size()-1].begin(), dp[triangle.size()-1].end());
    }
};