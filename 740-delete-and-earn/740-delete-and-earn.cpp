class Solution 
{
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        map<int,int> m;
        int maxn=0;
        for(int i=0;i<nums.size();++i)
        {
            m[nums[i]]+=nums[i];
            maxn = max(maxn,nums[i]);
        }
        
        vector<int> dp(maxn+1,0);
        dp[1]=m[1];
        
        for(int i=2;i<maxn+1;++i)
            dp[i] = max(dp[i-1], dp[i-2]+m[i]);
        return dp.back();
    }
};