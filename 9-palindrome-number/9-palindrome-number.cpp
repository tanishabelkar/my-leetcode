class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0)
            return false;
        vector<int> num;
        while(x)
        {
            num.push_back(x%10);
            x/=10;
        }
        int i=0,j=num.size()-1;
        while(i<=j)
        {
            if(num[i]!=num[j])
                return false;
            ++i, --j;
        }
        return true;
    }
};