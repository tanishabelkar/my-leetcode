class Solution
{
    public:
        double myPow(double x, int n)
        {
            if (x == 0)
                return 0;
            else if (n == 1)
                return x;
            else if (n == 0 || x == 1)
                return 1;

            if (n < 0)
            {
                x = 1 / x;
                if (n >= INT_MIN + 1)
                {
                    n *= -1;
                }
                else
                {
                    return x * myPow(1/x, n + 1);
                }
            }
            if (n % 2 == 0)
                return myPow(x *x, n / 2);
            else
                return x* myPow(x, n - 1);
        }
};