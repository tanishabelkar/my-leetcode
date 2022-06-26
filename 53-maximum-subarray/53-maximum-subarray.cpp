class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int lsum=0, ans=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            lsum=max(nums[i], nums[i]+lsum);
            if(lsum>ans)
                ans=lsum;
        }
        return ans;
    }
};