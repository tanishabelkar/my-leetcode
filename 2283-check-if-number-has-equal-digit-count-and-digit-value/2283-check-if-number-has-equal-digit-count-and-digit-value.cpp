class Solution 
{
public:
    bool digitCount(string num) 
    {
        map<int, int> m;
        for(auto c:num)
            ++m[c-'0'];
        for(int i=0;i<num.size();++i)
        {
            if(m[i]!=(num[i]-'0'))
            {
                cout<<i<<" ";
                return false;
            }
        }
        return true;
    }
};