class Solution
{
    public:
        bool isPal(string s)
        {
            int i = 0, j = s.size() - 1;
            while (i <= j)
            {
                if (s[i] != s[j])
                    return false;
                ++i, --j;
            }
            return true;
        }
    bool isPalindrome(string s)
    {
        string s2 = "";
        for (auto c: s)
        {
            if (isalnum(c))
                s2 += (tolower(c));
        }
        return isPal(s2);
    }
};