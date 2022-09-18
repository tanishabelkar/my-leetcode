class Solution
{
    public:
        string addBinary(string a, string b)
        {
            string res = "";
            bool carry = false;
            int i, j;
            for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; --i, --j)
            {
                if (a[i] == '0' && b[j] == '0')
                {
                    if (carry)
                    {
                        res = '1' + res;
                        carry = false;
                    }
                    else res = '0' + res;
                }
                if (a[i] == '0' && b[j] == '1' || a[i] == '1' && b[j] == '0')
                {
                    if (carry)
                        res = '0' + res;
                    else
                        res = '1' + res;
                }
                if (a[i] == '1' && b[j] == '1')
                {
                    if (carry)
                        res = '1' + res;
                    else
                    {
                        res = '0' + res;
                        carry = true;
                    }
                }
            }

            while (i >= 0)
            {
                if (carry)
                {
                    if (a[i] == '0')
                    {
                        carry = false;
                        res = '1' + res;
                    }
                    else
                        res = '0' + res;
                }
                else
                    res = a[i] + res;
                --i;
            }
            while (j >= 0)
            {
                if (carry)
                {
                    if (b[j] == '0')
                    {
                        carry = false;
                        res = '1' + res;
                    }
                    else res = '0' + res;
                }
                else
                    res = b[j] + res;
                --j;
            }
            if (carry)
                res = '1' + res;
            return res;
        }
};