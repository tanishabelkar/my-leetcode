class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        for (i = nums.size()-1; i>0;--i)
        {
            if (nums[i] > nums[i-1])
                break;
        }
        --i;
        if (i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // find the smallest number > nums[i], then swap it w nums[i] and sort the remaining array
        int sm = i+1, j = i+1;
        while (j < nums.size())
        {
            if (nums[j] > nums[i] && nums[j] < nums[sm])
                sm = j;
            ++j;
        }
        swap(nums[i], nums[sm]);
        sort(nums.begin()+i+1, nums.end());
    }
};