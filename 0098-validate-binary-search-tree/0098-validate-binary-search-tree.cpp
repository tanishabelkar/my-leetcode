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
    bool isSorted(vector<int> &v)
    {
        for (int i = 1; i<v.size(); ++i)
        {
            if (v[i]<=v[i-1])
                return false;
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty() || root != nullptr)
        {
            while (root)
            {
                st.push(root);
                root=root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return isSorted(res);
    }
};