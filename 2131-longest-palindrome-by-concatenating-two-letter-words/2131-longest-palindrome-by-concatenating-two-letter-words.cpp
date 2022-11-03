class Solution
{
    public:
        int longestPalindrome(vector<string> &words)
        {
            int ans = 0;
            unordered_map<string, int> freq;
            for (auto w: words)
                freq[w] += 1;
            
            bool mid = false;
            for (auto it: freq)
            {
                string w = it.first;
                if (w[0] == w[1])
                {
                    if (freq[w]%2 == 0)
                        ans += freq[w];
                    else if (!mid)
                    {
                        ans += freq[w];
                        mid = !mid;
                    }
                    else ans += (freq[w]-1);
                }
                else
                {
                    string rev = w;
                    reverse(rev.begin(), rev.end());
                    if (freq.find(rev) != freq.end())
                        ans += min(freq[rev], freq[w]);
                }
                
            }

            return ans*2;
        }
};