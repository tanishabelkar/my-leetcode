/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
    vector<vector<int>> res;
    void bft(Node *root, int level)
    {
        if (root)
        {
            res[level].push_back(root->val);
            for (auto c: root->children)
                bft(c, level + 1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        if(!root)
            return res;
        res.resize(1000);
        bft(root, 0);
        int beg = 0, end = 999, mid;
        while (beg <= end)
        {
            mid = (beg+end)/2;
            if(res[mid].size() == 0 && res[mid - 1].size() > 0)
                break;
            else if (res[mid].size() > 0)
                beg = mid + 1;
            else end = mid - 1;
        }
        res.resize(mid);        
        return res;
    }
};