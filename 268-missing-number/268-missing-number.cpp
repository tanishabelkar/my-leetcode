class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int s=0, m=nums.size();
        for(auto n:nums)
            s+=n;
        return abs(s-m*(m+1)/2);
    }
};