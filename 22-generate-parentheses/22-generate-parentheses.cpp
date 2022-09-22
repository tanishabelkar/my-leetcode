class Solution 
{
    vector<string> res;
public:
    
    void backtrack(string temp, int n, int open, int close)
    {
        if (temp.size() == n*2)
        {
            res.push_back(temp);
            return;
        }
        
        if (open < n)
        {
            temp += "(";
            backtrack(temp, n, open + 1, close);
            temp.pop_back();
        }
        
        if (close < open)
        {
            temp += ")";
            backtrack(temp, n, open, close + 1);
            temp.pop_back();
        }     
    }
    
    vector<string> generateParenthesis(int n) 
    {
        
        backtrack("", n, 0, 0);
        return res;
    }
};