class Solution {
public:
          
    int lengthOfLongestSubstring(string s) 
    {
        int i=0,j=0, res=0;
        map<char, int> m;
        while(j<s.size())
        {
            if(m.find(s[j])==m.end())
                m[s[j]]=j;
            else
            {
                if(m[s[j]]>=i)
                    i=m[s[j]]+1;
                m[s[j]]=j;
            }
            res=max(res, j-i+1);
            ++j;
        }
        return res;
    }
};