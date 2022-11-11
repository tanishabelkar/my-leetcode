class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            int start = 0, i = 1;
            while (i < nums.size())
            {
                if (nums[i] != nums[start])
                {
                    nums[start + 1] = nums[i];
                    ++start;
                }
                ++i;
            }
            return start + 1;
        }
};