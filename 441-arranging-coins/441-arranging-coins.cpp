class Solution
{
    public:
        int arrangeCoins(int n)
        {
            if (n == 1)
                return 1;
            int b = 0, e = n;
            while (b <= e)
            {
                long long int mid = (b + e) / 2, x;
                if (mid & 1)
                    x = (mid + 1) / 2 * mid;
                else x = mid / 2 *(mid + 1);
                if (x == n)
                    return mid;
                else if (x > n)
                    e = mid - 1;
                else
                    b = mid + 1;
            }
            return e;
        }
};