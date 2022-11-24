class Solution
{
    public:
        int countDays(vector<int> &v, int cap)
        {
            int ans = 0, i = 0, s = 0;
            while (i < v.size())
            {
                s = 0;
                while (i < v.size() && s + v[i] <= cap)
                {
                    s += v[i];
                    ++i;
                }
                ++ans;
            }
            return ans;
        }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int beg = *max_element(weights.begin(), weights.end()), end = 0, mid;
        end = accumulate(weights.begin(), weights.end(), end);

        while (beg <= end)
        {
            mid = beg + (end - beg) / 2;
            int c = countDays(weights, mid);

            if (c <= days)
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return beg;
    }
};