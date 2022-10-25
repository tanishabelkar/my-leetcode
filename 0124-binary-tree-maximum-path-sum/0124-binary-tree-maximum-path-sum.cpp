class Solution 
{
    int ans;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        
        int leftMax = max(0,dfs(root->left)), rightMax = max(0,dfs(root->right));
        
        ans = max(ans, root->val+leftMax+rightMax);
        return max(leftMax, rightMax)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        ans = root->val;
        dfs(root);
        // cout << x;
        return ans;
    }
};