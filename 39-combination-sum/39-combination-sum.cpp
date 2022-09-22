class Solution 
{
    vector<vector<int>> res;
public:
    
    void backtrack(vector<int> can, vector<int> temp, int idx, int currSum, int k)
    {
        if(currSum > k)
            return;
        else if (currSum == k)
        {
            res.push_back(temp);
            return;
        }
        
        for (int i = idx; i < can.size(); ++i)
        {
            temp.push_back(can[i]);
            backtrack(can, temp, i, currSum + can[i], k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        backtrack(candidates, {}, 0, 0, target);
        return res;
    }
};