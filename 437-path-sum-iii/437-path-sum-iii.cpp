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
    
    int dft(TreeNode *root, long long int p, int target)
    {
        if (!root)
            return 0;
        
        int ans = 0;
        if (p == target - root->val)
            ans += 1;
        ans += dft(root->left, p + root->val, target);
        ans += dft(root->right, p + root->val, target);
        return ans;
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        if (root == nullptr)
            return 0;
        
        return dft(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};