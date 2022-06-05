class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res(2);
        res[0]=1, res[1]=nums.size();
        while(res[0]<res[1])
        {
            if(nums[res[0]-1]+nums[res[1]-1]>target)
                --res[1];
            else if(nums[res[0]-1]+nums[res[1]-1]<target)
                ++res[0];
            else
                return res;
        }
        return vector<int>();
    }
};