class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int pos=0;
        while(pos<nums.size()&&nums[pos]<0)
        {
            pos++;
        }
        //cout<<pos<<"-";
        vector<int> res(nums.size());
        int i=pos-1, j=pos, k=0;
        while(j<nums.size() && i>=0)
        {
            if(nums[i]*nums[i] < nums[j]*nums[j])
            {
                res[k++]=nums[i]*nums[i];
                --i;
            }
            else
            {
                res[k++]=nums[j]*nums[j];
                ++j;
            }
        }
        while(j<nums.size())
        {
            res[k++]=nums[j]*nums[j];
            ++j;
        }
        while(i>=0)
        {
            res[k++]=nums[i]*nums[i];
            --i;
        }
        return res;
    }
};