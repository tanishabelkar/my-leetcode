class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
           	// all elements appear atmost twice!!

            int beg = 0, end = nums.size() - 1, mid;
            while (beg <= end)
            {
                mid = beg + (end - beg) / 2;
                if (mid == 0 || mid == nums.size() - 1 || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
                    return nums[mid];

                else if ((mid % 2 == 0 && nums[mid] == nums[mid - 1]) || (mid % 2 == 1 && nums[mid] == nums[mid + 1]))
                    end = mid - 1;
                else beg = mid + 1;
            }

            return -1;
        }
};