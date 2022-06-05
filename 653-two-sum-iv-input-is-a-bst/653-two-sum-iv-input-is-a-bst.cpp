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
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==nullptr)
            return false;
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode *curr=root;
        
        while(curr!=nullptr || !s.empty())
        {
            while(curr!=nullptr)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        
        int i=0, j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k)
                return true;
            else if(v[i]+v[j]<k)
                ++i;
            else --j;
        }
        return false;
    }
};