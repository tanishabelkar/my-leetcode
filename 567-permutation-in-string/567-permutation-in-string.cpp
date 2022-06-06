class Solution 
{
public:
    
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size()>s2.size())
            return false;
        int n=s1.size();
        map<char, int> m, target;
        for(int i=0;i<n;++i)
        {
            ++m[s2[i]];
            ++target[s1[i]];
        }
        if(m.size()==target.size()&&equal(m.begin(), m.end(), target.begin()))
            return true;
        
        int k=1;
        for(int i=n;i<s2.size();++i, ++k)
        {
            --m[s2[k-1]];
            if(m[s2[k-1]] <= 0)
                m.erase(s2[k-1]);
            ++m[s2[i]];
            if(m.size()==target.size()&&equal(m.begin(), m.end(), target.begin()))
                return true;
        }
        return false;
    }
};