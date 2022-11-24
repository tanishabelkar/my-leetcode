class Solution
{
    public:
        int countDays(vector<int> v, int cap)
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
    int sumOf(vector<int> &b)
    {
        int s=0;
        for(auto x:b) s+=x;
        return s;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int beg = *max_element(weights.begin(), weights.end()), end = sumOf(weights), mid;

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