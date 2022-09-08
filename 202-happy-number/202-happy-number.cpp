class Solution
{
    map<int, int> m;
    public:

        bool isHappy(int n)
        {
            if (n == 1)
                return true;
            else if (m[n] != 0)
            {
                cout<<n<<" "<<m[n];
                return false;
            }
            else
            {
                m[n] = 1;
                int sum = 0;
                while (n > 0)
                {
                    sum += pow(n % 10, 2);
                    n /= 10;
                }
                return isHappy(sum);
            }
        }
};