class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int count = 1, m = nums[0];
            for (int i = 1; i < nums.size(); ++i)
            {
                if (count == 0)
                    m = nums[i];
                if (nums[i] == m)
                    ++count;
                else
                    --count;
            }
            return m;
        }
};