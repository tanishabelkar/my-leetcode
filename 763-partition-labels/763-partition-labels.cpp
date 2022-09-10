class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            vector<int> res;
            
            unordered_map<char, int> last;
            for (int i = 0; i < s.size(); ++i)
                last[s[i]] = i;
            
            int i = 0;
            while (i < s.size())
            {
                int l = last[s[i]], j = i;
                while (j < l)
                {
                    if (last[s[j]] > l)
                        l = last[s[j]];
                    ++j;
                }
                res.push_back(l);
                i = l + 1;
            }
            
            vector<int> res2(res.size());
            res2[0] = res[0] + 1;
            for (int i = 1; i < res2.size(); ++i)
                res2[i] = res[i] - res[i - 1];
            return res2;
        }
};