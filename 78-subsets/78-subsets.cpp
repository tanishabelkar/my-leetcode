class Solution 
{
    vector<bool> vis;
    vector<vector<int>> res;
public:
    
    void backtrack(vector<int> nums, vector<int> temp, int i, int n)
    {
        if(temp.size() == n)
        {
            res.push_back(temp);
            return;
        }
        for (int j = i; j < nums.size(); ++j)
        {
            if (!vis[j])
            {
                vis[j] = true;
                temp.push_back(nums[j]);
                backtrack(nums, temp, j, n);
                temp.pop_back();
                vis[j] = false;
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vis.resize(nums.size());
        for(int i = 0; i < nums.size(); ++i)
            backtrack(nums, {}, 0, i);
        res.push_back(nums);
        return res;
    }
};