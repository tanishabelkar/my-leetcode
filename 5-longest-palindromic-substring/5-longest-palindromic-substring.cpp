class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int n = s.size(), a = 0, b = 0;
            bool dp[n][n];
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j <= i; ++j)
                {
                    if (i == j)
                        dp[i][j] = true;
                    else
                    {
                        bool x = (s[i] == s[j]);
                        if (x && i - 1 > j + 1)
                            x = x &dp[i - 1][j + 1];
                        dp[i][j] = x;
                    }
                    if (dp[i][j] && i - j > a - b)
                    {
                        a = i;
                        b = j;
                    }
                }
            }
           	//cout<<a<<" "<<b<<"\n";
            return s.substr(b, a - b + 1);
        }
};