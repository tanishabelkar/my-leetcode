class Solution 
{
public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int> ind;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == c)
                ind.push_back(i);
        }
        
        vector<int> res(s.size(), INT_MAX);
        
        for(int i=0;i<s.size();++i)
        {
            for(int j=0;j<ind.size();++j)
                res[i]=min(abs(ind[j] - i), res[i]);
        }
        return res;
    }
};