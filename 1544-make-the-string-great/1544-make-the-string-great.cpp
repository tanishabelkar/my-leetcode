class Solution
{
public:
    bool isGood(char &a, char &A)
    {
        return (int)(a - 'a') == (int)(A - 'A') || (int)(a - 'A') == (int)(A - 'a');
    }
    
    
    string makeGood(string s)
    {
        string res = "";

        for (int i = 0; i < s.size(); ++i)
        {
            if (res.empty())
                res.push_back(s[i]);
            else
            {
                if (isGood(res.back(), s[i]))
                    res.pop_back();
                else 
                    res.push_back(s[i]);
            }
        }
        
        return res;
    }
};