class Solution 
{
public:
    int strStr(string h, string n) 
    {
        if(n.empty())
            return 0;
        int res=-1;
        int i=0, j=0;
        while(i<h.size())
        {
            while(h[i]==n[j])
            {
                ++i, ++j;
                if(j>=n.size())
                    return i-n.size();
            }
            if(j>0)
            {
                i-=j;
                j=0;
            }
            ++i;
        }
        return -1;
    }
};