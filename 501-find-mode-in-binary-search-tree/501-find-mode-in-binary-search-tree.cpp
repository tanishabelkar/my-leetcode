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
    unordered_map<int, int> freq;
public:
    
    void dft(TreeNode *root)
    {
        if (!root)
            return;
        freq[root->val] += 1;
        dft(root->left);
        dft(root->right);
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> res;
        dft(root);
        
        int m = INT_MIN;
        for (auto f: freq)
            m = max(m,f.second);
        
        for (auto f: freq)
        {
            if (f.second == m)
                res.push_back(f.first);
        }
        
        return res;
    }
};