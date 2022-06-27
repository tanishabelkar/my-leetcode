class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans=nums[0], pos=nums[0], neg=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            int t=max({pos*nums[i], neg*nums[i], nums[i]});
            neg=min({pos*nums[i], neg*nums[i], nums[i]});
            pos=t;
            ans=max(ans,pos);
        }
        return ans;
    }
};