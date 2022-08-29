class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            vector<int> diff(prices.size() - 1);
            for (int i = 0; i < prices.size() - 1; ++i)
                diff[i] = prices[i + 1] - prices[i];

            int lsum = 0, gsum = INT_MIN;
            for (int i = 0; i < diff.size(); ++i)
            {
                lsum = max(diff[i], diff[i] + lsum);
                gsum = max(lsum, gsum);
            }
            
            if (gsum < 0)
                return 0;
            
            return gsum;
        }
};