class Solution
{
    public:
        int getMaxLen(vector<int> &nums)
        {
            int i = 0, j, ans = INT_MIN;
            while (i < nums.size())
            {
                while (i < nums.size() && nums[i] == 0) ++i;
                j = i + 1;
                while (j < nums.size() && nums[j] != 0) ++j;
                j -= 1;
                int neg = 0;
                for (int k = i; k <= j; ++k)
                {
                    if (nums[k] < 0)
                        ++neg;
                }
                if (neg % 2 == 1)
                {
                    int p = i, s = j;
                    while (p < j)
                    {
                        if (nums[p] < 0)
                            break;
                        ++p;
                    }
                    while (s > i)
                    {
                        if (nums[s] < 0)
                            break;
                        --s;
                    }
                    ans = max({ ans,
                        s - i,
                        j - p });
                }
                else ans = max(ans, j - i + 1);

                i = j + 1;
            }
            return ans;
        }
};