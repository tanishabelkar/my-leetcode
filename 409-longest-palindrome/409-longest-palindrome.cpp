class Solution {
public:
    int longestPalindrome(string s) 
    {
        map<char, int> freq;
        for (auto c:s)
            freq[c]++;
        int res = 0;
        for (auto i:freq)
            res += (i.second/2 * 2);
        
        if (res < s.size())
            res += 1;
        return res;
    }
};