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
    vector<string> ans;
    unordered_map<TreeNode*, bool> vis;
    
    string toString(int x)
    {
        if (x == 0)
            return "0";
        bool neg = (x < 0);
        if(neg) x*=(-1);
        string res = "";
        while (x)
        {
            res = (char)(x%10 + '0') + res;
            x/=10;
        }
        if(neg)
            return "-"+res;
        return res;
    }
public:
    
    void backtrack(TreeNode *root, string temp)
    {
        if (!root)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            temp += toString(root->val);
            ans.push_back(temp);
        }
        
        if (vis[root] == false)
        {
            vis[root] = true;
            temp += (toString(root->val)+"->");
            backtrack(root->left, temp);
            backtrack(root->right, temp);
            vis[root] = false;
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        backtrack(root, "");
        return ans;
    }
};