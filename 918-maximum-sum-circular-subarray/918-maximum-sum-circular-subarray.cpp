class Solution
{
    public:

        int maxSubarraySumCircular(vector<int> &nums)
        {
            int maxs = nums[0], lsum = nums[0], sum = nums[0], mins = nums[0], rsum = nums[0];
            for (int i = 1; i < nums.size(); ++i)
            {
                sum += nums[i];
                lsum = max(lsum + nums[i], nums[i]);
                maxs = max(lsum, maxs);

                rsum = min(rsum + nums[i], nums[i]);
                mins = min(rsum, mins);
            }
           	//cout<<sum<<" "<<maxs<<" "<<mins<<"\n";
            if (mins == sum)
                return maxs;
            return max(sum - mins, maxs);
        }
};