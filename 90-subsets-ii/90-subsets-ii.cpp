class Solution
{
    vector<vector < int>> res;
    public:

        void backtrack(vector<int> nums, vector<int> temp, int i)
        {
            res.push_back(temp);
            
            int j = i;
            while (j < nums.size())
            {
                temp.push_back(nums[j]);
                backtrack(nums, temp, j + 1);
                temp.pop_back();
                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    ++j;
                ++j;
            }
        }

    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        backtrack(nums, {}, 0);
        return res;
    }
};