class Solution
{
    public:
        int help(int x, int y)
        {
            while (x % y == 0)
                x /= y;
            return x;
        }
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        for (auto factor:
            {
                2,
                3,
                5 })
            n = help(n, factor);

        return n == 1;
    }
};