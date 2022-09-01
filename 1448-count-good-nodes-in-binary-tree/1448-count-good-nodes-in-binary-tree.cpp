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
    int ans;
    public:

        void calc(TreeNode *t, int n)
        {
            if (t == nullptr)
                return;

            if (n <= t->val)
            {
                // cout << t->val << " ";
                ans += 1;
                calc(t->left, t->val);
                calc(t->right, t->val);
            }
            else
            {
                calc(t->right, n);
                calc(t->left, n);
            }
        }

    int goodNodes(TreeNode *root)
    {
        if(!root)
            return 0;
        
        ans = 1;
        calc(root->left, root->val);
        calc(root->right, root->val);
        return ans;
    }
};