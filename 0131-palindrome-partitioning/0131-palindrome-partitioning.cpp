class Solution 
{
    vector<vector<string>> res;
    bool isPal(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i<=j)
        {
            if (s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }
public:
    void backtrack(string s, int ind, vector<string> temp)
    {
        if (ind >= s.size())
        {
            res.push_back(temp);
            return;
        }
        
        for (int i = ind; i < s.size(); ++i)
        {
            string x = s.substr(ind, i-ind+1);
            if (isPal(x))
            {
                temp.push_back(x);
                backtrack(s, ind+x.size(), temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        backtrack(s, 0, {});
        return res;
    }
};