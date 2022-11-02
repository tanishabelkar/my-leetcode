/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    bool leafNode(TreeNode*root)
    {
        if (!root)
            return false;
        else
            return (root->left == nullptr && root->right == nullptr);
    }
    public:
        bool evaluateTree(TreeNode *root)
        {
            if (!root)
                return false;
            if (leafNode(root))
                return root->val;
            bool l = evaluateTree(root->left), r = evaluateTree(root->right);
            return (root->val == 2) ? l || r : l && r;
        }
};