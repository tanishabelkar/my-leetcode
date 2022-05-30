// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int beg=0, end=n;
        while(beg<end)
        {
            int mid=beg+(end-beg)/2;
            bool res=isBadVersion(mid);
            if(res)
            {
                end=mid;
            }
            else
            {
                if(isBadVersion(mid+1))
                    return mid+1;
                else beg=mid+1;
            }
        }
        return n;
    }
};