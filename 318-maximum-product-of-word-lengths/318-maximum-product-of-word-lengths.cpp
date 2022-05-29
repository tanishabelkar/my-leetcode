class Solution
{
    public:
        int stringToInt(string s)
        {
            int res = 0;
            for (int j = 0; j < s.size(); ++j)
            {
                int bit = s[j] - 'a';
                res |= (1 << bit);
            }
            return res;
        }

    int maxProduct(vector<string> &words)
    {
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((stringToInt(words[i]) & stringToInt(words[j])) == 0)
                {
                    if (res < words[i].size() *words[j].size())
                        res = words[i].size() *words[j].size();
                }
            }
        }
        return res;
    }
};