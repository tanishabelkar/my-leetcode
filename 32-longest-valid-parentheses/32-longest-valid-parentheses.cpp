class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            vector<int> dp(s.size() + 1, 0);
            int i = 1;
            while (i < s.size())
            {
                if (s[i] == ')')
                {
                    if (s[i - 1] == '(')
                    {
                        if (i - 2 >= 0)
                            dp[i] = dp[i - 2] + 2;
                        else dp[i] = 2;
                    }
                    if (s[i - 1] == ')')
                    {
                        if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                            dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                }
                ++i;
            }

            return *max_element(dp.begin(), dp.end());
        }
};