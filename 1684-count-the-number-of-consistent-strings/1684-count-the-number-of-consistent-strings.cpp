class Solution 
{
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        map<char, int> a;
        int ans=0;
        for(auto c: allowed) ++a[c];
        for(auto w:words)
        {
            bool flag=true;
            for(auto c:w)
            {
                if(a[c]<=0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ++ans;
        }
        
        return ans;
    }
};