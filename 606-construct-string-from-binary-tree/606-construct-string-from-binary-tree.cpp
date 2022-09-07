/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    string ans = "";
    public:

        string toStr(int n)
        {
            if (n == 0)
                return "0";
            if (n < 0)
                n *= (-1);
            string res = "";

            while (n)
            {
                res += ('0' + n % 10);
                n /= 10;
            }

            reverse(res.begin(), res.end());

            return res;
        }

    void help(TreeNode *t)
    {
        ans += '(';
        if (t)
        {
            if (t->val < 0)
                ans += ('-' + toStr(t->val));
            else ans += toStr(t->val);
        }
        if (t)
        {
            if (t->left != nullptr || t->right != nullptr)
                help(t->left);
            if (t->right != nullptr)
                help(t->right);
        }
        ans += ')';
    }

    string tree2str(TreeNode *root)
    {
        help(root);
        return ans.substr(1, ans.size() - 2);
    }
};