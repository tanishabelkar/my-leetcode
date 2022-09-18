/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isValidBST(TreeNode *root)
        {
            if (root == NULL)
                return true;

            stack<TreeNode*> s;
            int last;
            bool vis = false;
            while (!s.empty() || root != NULL)
            {
                while (root != NULL)
                {
                    s.push(root);
                    root = root->left;
                }
                root = s.top();
                s.pop();
                if (vis && root->val <= last)
                    return false;
                last = root->val;
                vis = true;
                root = root->right;
            }
            return true;
        }
};