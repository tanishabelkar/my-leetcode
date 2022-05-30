class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if(target<=nums[0]) return 0;
        if(target>nums[nums.size()-1]) return nums.size();
        int beg=0, end=nums.size()-1, mid;
        while(beg<=end)
        {
            //cout<<beg<<" "<<end<<" ";
            mid=(beg+end)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                beg=mid+1;
            else end=mid-1;
            
        }
        return beg;
    }
};