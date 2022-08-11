class Solution
{
    public:
        int countKDifference(vector<int> &nums, int k)
        {
            map<int, int> freq;
            for (auto n: nums) ++freq[n];
            int ans = 0;

            for (auto f: freq)
            {
                if(k == 0)
                {
                    if(f.second > 1)
                        ans += (f.second - 1);
                }
                else if (freq.find(k + f.first) != freq.end())
                    ans += (f.second * freq[k + f.first]);
                
                // cout<<f.first<<" "<<ans<<"\n";
            }

            return ans;
        }
};