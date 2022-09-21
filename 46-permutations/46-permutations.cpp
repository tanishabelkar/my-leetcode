class Solution 
{
    map<int, bool> vis;
    vector<vector<int>> res;
public:
    
    void backtrack(vector<int>nums, vector<int> temp)
    {
        if (temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (vis[i] == false)
            {
                vis[i] = true;
                temp.push_back(nums[i]);
                backtrack(nums, temp);
                vis[i] = false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        backtrack(nums, temp);
        return res;
    }
};