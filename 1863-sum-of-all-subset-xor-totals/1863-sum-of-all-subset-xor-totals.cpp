class Solution
{
    int ans;
    unordered_map<int, bool> vis;

    int totalXor(vector<int> v)
    {
        int res = 0;
        for (auto a: v)
            res = (res ^ a);
        return res;
    }
    public:

        void backtrack(vector<int> nums, vector<int> temp, int i, int n)
        {
            if (temp.size() == n)
            {
                ans += totalXor(temp);
                return;
            }
            for (int j = i; j < nums.size(); ++j)
            {
                if (!vis[j])
                {
                    vis[j] = true;
                    temp.push_back(nums[j]);
                    backtrack(nums, temp, j, n);
                    temp.pop_back();
                    vis[j] = false;
                }
            }
        }

    int subsetXORSum(vector<int> &nums)
    {
        ans = totalXor(nums);
        for (int i = 0; i < nums.size(); ++i)
            backtrack(nums, {}, 0, i);
        return ans;
    }
};