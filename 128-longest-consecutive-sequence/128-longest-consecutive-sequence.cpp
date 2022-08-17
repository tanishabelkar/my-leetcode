class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if(nums.size() == 0)
                return 0;
            map<int, int> m;
            int ans = INT_MIN, local = 1, prev;
            for (auto n: nums) ++m[n];

            map<int, int>::iterator it = m.begin();
            prev = it->first;
            it++;

            for (; it != m.end(); it++)
            {
                if (it->first == prev + 1)
                    local += 1;
                else
                {
                    ans = max(local, ans);
                    local = 1;
                }
                prev = it->first;
            }
            ans = max(ans, local);
            return ans;
        }
};