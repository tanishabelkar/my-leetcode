class Solution {
public:
    int rob(vector<int>& nums) 
    {
        switch (nums.size())
        {
            case 0: return 0;
            case 1: return nums[0];
            case 2: return max(nums[0],nums[1]);
            case 3: return max({nums[0],nums[1],nums[2]});
            default: break;
        }
        int ans1=0, ans2=0, a=0, b=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            ans1=max(a+nums[i], b);
            a=b;
            b=ans1;
        }
        a=b=0;
        for(int i=1;i<nums.size();++i)
        {
            ans2=max(a+nums[i], b);
            a=b;
            b=ans2;
        }
        return max(ans1, ans2);
    }
};