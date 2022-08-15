class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int sp, tp;
        sp = tp = 0;
        while (tp < t.size())
        {
            if (t[tp] == s[sp])
                ++sp;
            ++tp;
        }
        return (sp == s.size());
    }
};