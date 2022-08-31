class Solution
{
    public:
        int maxScoreSightseeingPair(vector<int> &values)
        {
            if (values.size() == 2)
                return values[0] + values[1] - 1;

            int ans = INT_MIN, l=0;
            
            for (int i = 1; i < values.size(); ++i)
            {
                ans=max(ans, values[l]+values[i]+l-i);
                if(values[i]+i >= values[l]+l)
                    l=i;
            }
            
            return ans;
        }
};