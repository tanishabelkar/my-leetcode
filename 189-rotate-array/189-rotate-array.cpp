class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int n = nums.size();
            k = k % n;
            if (k == 0)
                return;

            vector<int> temp(k);
            int j = 0;
            for (int i = n - k; i < n; ++i)
                temp[j++] = nums[i];

            for (int i = n - 1 - k; i >= 0; --i)
                nums[i + k] = nums[i];

            for (int i = 0; i < k; ++i)
                nums[i] = temp[i];
        }
};