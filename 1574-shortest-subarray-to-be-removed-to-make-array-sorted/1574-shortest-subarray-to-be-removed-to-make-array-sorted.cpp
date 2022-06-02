class Solution 
{
public:
    
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int beg=0, end=arr.size()-1;
        while(beg<arr.size()-1 && arr[beg]<=arr[beg+1])
            ++beg;
        while(end>0 && arr[end-1]<=arr[end])
            --end;
        
        if(beg>=end)
            return 0;
        
        int ans=INT_MAX;
        int p=beg;
        while(p>=0)
        {
            int q=end;
            while(q<arr.size() && arr[q]<arr[p])
                q++;
            //cout<<p<<" "<<q<<"\n";
            ans=min(ans, q-p-1);
            --p;
        }
        
        int q=end;
        while(q<arr.size())
        {
            int p=beg;
            while(p>=0 && arr[q]<arr[p])
                --p;
            //cout<<p<<" "<<q<<"\n";
            ans=min(ans, q-p-1);
            ++q;
        }
        return ans;
    }
};