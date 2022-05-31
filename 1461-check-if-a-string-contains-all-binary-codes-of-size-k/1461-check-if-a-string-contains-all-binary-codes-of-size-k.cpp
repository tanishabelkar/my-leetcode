class Solution 
{
public:
    
    int toInt(string s)
    {
        int res=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1')
                res|=(1<<(s.size()-i-1));
        }
        return res;
    }
    
    bool hasAllCodes(string s, int k) 
    {
        if(k>s.size())
            return false;
        unordered_set<int> st;
        for(int i=0;i<=s.size()-k;++i)
            st.insert(toInt(s.substr(i,k)));
        return st.size()==(1<<k);
    }
};