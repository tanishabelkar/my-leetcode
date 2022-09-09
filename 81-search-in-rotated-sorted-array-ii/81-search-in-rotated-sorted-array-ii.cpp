class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        int beg=0, end=nums.size()-1;
        //reduce search space
        while(beg<=end && nums[beg] == nums[end])
        {
            if(nums[beg] == target)
                return true;
            ++beg, --end;
        }
        
        //search in reduced space
        while(beg<=end)
        {
            int mid = beg + (end - beg)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] >= nums[beg])
            {
                if(target < nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else beg = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[end])
                    beg = mid+1;
                else end = mid -1;
            }
        }
        
        return false;
    }
};