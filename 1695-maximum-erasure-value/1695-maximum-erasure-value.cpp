class Solution 
{
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        set<int> s;
        int l=0, r=0, res=INT_MIN, cur=0;
        
        for(r=0;r<nums.size();++r)
        {
            while(s.find(nums[r])!=s.end())
            {
                cur-=nums[l];
                s.erase(nums[l++]);
            }
            s.insert(nums[r]);
            cur+=nums[r];
            res=max(res, cur);
        }
        return res;
    }
};