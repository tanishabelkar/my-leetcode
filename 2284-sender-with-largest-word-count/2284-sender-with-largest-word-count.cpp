class Solution
{
    public:
        int wordcount(string s)
        {
            int ans = 1;
            int i = 0;
            while (i < s.size())
            {
                if (s[i] == ' ')
                    ++ans;
                ++i;
            }
            return ans;
        }
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> m;
        for (int i = 0; i < senders.size(); ++i)
        {
            m[senders[i]] += wordcount(messages[i]);
        }
        int ans = INT_MIN;
        string per;
        for (auto c: m)
        {
            if(c.second>=ans)
            {
                per=c.first;
                ans=c.second;
            }
        }
        return per;
    }
};