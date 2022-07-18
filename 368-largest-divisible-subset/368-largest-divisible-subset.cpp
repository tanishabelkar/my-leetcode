class Solution
{
    public:
        vector<int> largestDivisibleSubset(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            
            vector<vector < int> > dp(nums.size());
            dp[0].push_back(nums[0]); //base case
            
            for (int i = 1; i < nums.size(); ++i)
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (nums[i] % nums[j] == 0)
                    {
                        if (dp[j].size() + 1 > dp[i].size())
                        {
                            dp[i] = dp[j];
                            dp[i].push_back(nums[i]);
                        }
                    }
                }
                
                if (dp[i].size() == 0) //incase no element divides current element
                    dp[i].push_back(nums[i]);
            }

            int ml = dp[0].size(), mi = 0;
            for (int i = 1; i < dp.size(); ++i) //find maximum sized vector
            {
                if (ml < dp[i].size())
                {
                    ml = dp[i].size();
                    mi = i;
                }
            }
            return dp[mi];
        }
};