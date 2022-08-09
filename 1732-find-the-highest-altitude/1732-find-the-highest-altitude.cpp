class Solution 
{
public:
    int largestAltitude(vector<int>& gain) 
    {
        int s=0, m=INT_MIN;
        for(int i=0;i<gain.size();++i)
        {
            s+=gain[i];
            m=max(s,m);
        }
        return max(0,m);
    }
};