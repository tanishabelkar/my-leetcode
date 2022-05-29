class Solution
{
    public:
        int maxProduct(vector<string> &words)
        {
            vector<int> rep(words.size(), 0);
            for (int i = 0; i < words.size(); ++i)
            {
                for (int j = 0; j < words[i].size(); ++j)
                {
                    int bit = words[i][j] - 'a';
                    rep[i] |= (1 << bit);
                }
            }
           	//for(int i=0;i < rep.size();++i) cout<<rep[i]<<" ";
            int res = 0;
            for (int i = 0; i < rep.size(); i++)
            {
                for (int j = i + 1; j < rep.size(); j++)
                {
                    if ((rep[i] &rep[j]) == 0)
                    {
                        if (res < words[i].size() *words[j].size())
                            res = words[i].size() *words[j].size();
                    }
                }
            }
            return res;
        }
};