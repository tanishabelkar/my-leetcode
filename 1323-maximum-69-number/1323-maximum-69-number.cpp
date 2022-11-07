class Solution
{
    public:
        int maximum69Number(int num)
        {
            int res = 0;
            vector<int> n;
            while (num)
            {
                n.push_back(num % 10);
                num /= 10;
            }
            reverse(n.begin(), n.end());

            bool done = false;

            for (int i = 0; i < n.size(); ++i)
            {
                if (!done && n[i] == 6)
                {
                    res += 9 *(pow(10, n.size() - i - 1));
                    done = true;
                }
                else res += n[i] *(pow(10, n.size() - 1 - i));
            }

            return res;
        }
};