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
    vector<int> res;
    public:
    
        void dft(Node *root)
        {
            if (root)
            {
                res.push_back(root->val);
                for (auto c: root->children)
                    dft(c);
            }
        }

        vector<int> preorder(Node *root)
        {
            dft(root);
            return res;
        }
};