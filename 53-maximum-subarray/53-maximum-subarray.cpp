class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int lsum = 0, gsum = INT_MIN;
            for (int i = 0; i < nums.size(); ++i)
            {
                lsum = max(lsum + nums[i], nums[i]);
                gsum = max(gsum, lsum);
            }
            return gsum;
        }
};