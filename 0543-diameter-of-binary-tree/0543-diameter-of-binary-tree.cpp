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
    int ans;
    int help(TreeNode* t)
    {
        if (!t)
            return 0;
        int l = help(t->left), r = help(t->right);
        ans = max(ans, 1+l+r);
        return max(l,r)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        ans = 0;
        help(root);
        return ans-1;
    }
};