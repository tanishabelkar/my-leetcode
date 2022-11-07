class Solution
{
    public:
        string orderlyQueue(string s, int k)
        {
            if (k == 1)
            {
                string ans = s;
                for (int i = 0; i < s.size(); ++i)
                {
                    char temp = s[0];
                    s.erase(s.begin(), s.begin() + 1);
                    s.push_back(temp);

                    if (s.compare(ans) < 0)
                        ans = s;
                }
                return ans;
            }
            else
            {
                sort(s.begin(), s.end());
                return s;
            }
        }
};