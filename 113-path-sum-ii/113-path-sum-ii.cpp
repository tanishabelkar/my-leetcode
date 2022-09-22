/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> res;
    
    void backtrack(TreeNode *root, int target, int curr, vector<int> path)
    {
        if (!root)
            return;
        
        if (root->left == nullptr && root->right == nullptr && curr + root->val == target)
        {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        
        path.push_back(root->val);
        backtrack(root->left, target, curr+root->val, path);
        backtrack(root->right, target, curr+root->val, path);
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        backtrack(root, targetSum, 0, {});
        return res;
    }
};