class Solution
{
    public:
        int help(vector<int> &v, int i, int j)
        {
            int beg = j + 1, end = v.size() - 1, t = v[i] + v[j];
            while (beg <= end)
            {
                int mid = beg + (end - beg) / 2;
                if (v[mid] < t)
                    beg = mid + 1;
                else end = mid - 1;
            }
           	// cout << t << " " << beg << " " << end << "\n";
            return end;
        }
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            for (int j = i + 1; j < nums.size() - 1; ++j)
            {
                ans += (help(nums, i, j) - j);
            }
        }
        cout << ans << "\n";
        if (ans > 0)
            return ans;
        else return 0;
    }
};