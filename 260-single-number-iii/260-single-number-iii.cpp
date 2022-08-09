class Solution
{
    public:
        bool isSet(int n, int k)
        {
            return n & (1 << k);
        }

    vector<int> singleNumber(vector<int> &nums)
    {
        if (nums.size() == 2)
            return nums;

        int x = nums[0];
        vector<int> res(2, 0);
        for (int i = 1; i < nums.size(); ++i)
            x = (x ^ nums[i]);

        int pos = 0;
        while (pos < 31)
        {
            if (isSet(x, pos))
                break;
            ++pos;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (isSet(nums[i], pos))
                res[0] = (res[0] ^ nums[i]);
            else res[1] = (res[1] ^ nums[i]);
        }
        return res;
    }
};