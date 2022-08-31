class Solution
{
    public:
        int maxScoreSightseeingPair(vector<int> &values)
        {
            if (values.size() == 2)
                return values[0] + values[1] - 1;

            int ans = INT_MIN;
            vector<int> dp(values.size());
            dp[0] = values[0];

            for (int i = 1; i < values.size(); ++i)
                dp[i] = max(dp[i - 1], values[i] + i);
            for (int i = 1; i < dp.size(); ++i)
                ans = max(ans, dp[i - 1] + values[i] - i);

            return ans;
        }
};