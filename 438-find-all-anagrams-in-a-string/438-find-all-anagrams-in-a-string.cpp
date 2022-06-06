class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        if(p.size()>s.size())
            return res;
        vector<int> ms(26,0), mp(26,0);
        for(int k=0;k<p.size();++k)
                ++ms[s[k]-'a'];
        for(auto c:p)
            ++mp[c-'a'];
        
        int i1=0, i2=p.size()-1;
        while(i2<s.size())
        {
            if(ms==mp)
                res.push_back(i1);
            --ms[s[i1]-'a'];
            ++i1, ++i2;
            if(i2<s.size())
                ++ms[s[i2]-'a'];
            //cout<<"\n";
        }
        return res;
    }
};