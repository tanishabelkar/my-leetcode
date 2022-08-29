class Solution
{
    public:

        int findMin(vector<int> &n)
        {
            int lsum = n[0], gsum = n[0];
            for (int i = 1; i < n.size(); ++i)
            {
                lsum = min(n[i], lsum + n[i]);
                gsum = min(lsum, gsum);
            }
            return gsum;
        }

    int findMax(vector<int> &n)
    {
        int lsum = n[0], gsum = n[0];
        for (int i = 1; i < n.size(); ++i)
        {
            lsum = max(n[i], lsum + n[i]);
            gsum = max(lsum, gsum);
        }
        return gsum;
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        int maxs = INT_MIN, mins = INT_MAX;
        maxs = findMax(nums);
        mins = findMin(nums);
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) sum += nums[i];
        if (mins == sum)
            return maxs;
        else return max(maxs, sum - mins);
    }
};