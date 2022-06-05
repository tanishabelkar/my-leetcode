class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            int n = nums.size(), i = -1, j = 0;
            while (j < n)
            {
                if (nums[j] != 0)
                {
                    ++i;
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
                ++j;
            }
        }
};