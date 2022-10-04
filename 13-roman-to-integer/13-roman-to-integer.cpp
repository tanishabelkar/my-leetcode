class Solution
{
    int res;
    int value(char c)
    {
        switch (c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
    void func(string s, int idx)
    {
        if (idx >= s.size())
            return;
        cout<<res<<" ";
        if (s[idx] == 'I')
        {
            if (idx < s.size() - 1 && (s[idx + 1] == 'V' || s[idx + 1] == 'X'))
            {
                res += (value(s[idx + 1]) - value(s[idx]));
                func(s, idx + 2);
            }
            else
            {
                res += value(s[idx]);
                func(s, idx + 1);
            }
        }
        else if (s[idx] == 'X')
        {
            if (idx < s.size() - 1 && (s[idx + 1] == 'L' || s[idx + 1] == 'C'))
            {
                res += (value(s[idx + 1]) - value(s[idx]));
                func(s, idx + 2);
            }
            else
            {
                res += value(s[idx]);
                func(s, idx + 1);
            }
        }
        else if (s[idx] == 'C')
        {
            if (idx < s.size() - 1 && (s[idx + 1] == 'D' || s[idx + 1] == 'M'))
            {
                res += (value(s[idx + 1]) - value(s[idx]));
                func(s, idx + 2);
            }
            else
            {
                res += value(s[idx]);
                func(s, idx + 1);
            }
        }
        else
        {
            res += value(s[idx]);
            func(s, idx + 1);
        }
    }

    public:

        int romanToInt(string s)
        {
            res = 0;
            func(s, 0);
            return res;
        }
};