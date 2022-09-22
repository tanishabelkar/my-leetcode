class Solution 
{
    vector<vector<int>> res;
public:
    void backtrack(vector<int> temp, int k, int n, int ind)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
                
        for (int i = ind; i <= n; ++i)
        {
            temp.push_back(i);
            backtrack(temp, k, n, i + 1);
            temp.pop_back();
        }
    }
    
        
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> t;
        backtrack(t, k, n, 1);
        return res;
    }
};