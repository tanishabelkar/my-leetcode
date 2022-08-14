class Solution
{
    public:

        bool isSubstr(string s1, string s2)
        {
            int i = 0, j = 0;
            while (i < s1.size())
            {
                if (s1[i] == s2[j])
                    ++j;
                else
                {
                    if (j > 0)
                        i -= j;
                    j = 0;
                }
                ++i;
                if (j == s2.size())
                    return true;
            }
            return false;
        }

    bool rotateString(string s, string goal)
    {
        if (goal.size() != s.size())
            return false;
        s += s;
        return isSubstr(s, goal);
    }
};