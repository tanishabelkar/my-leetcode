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
    public:

        vector<int> preorder(Node *root)
        {
            // base case
            if (!root)
                return vector<int> ();

            vector<int> res;
            stack<Node*> s;

            s.push(root);

            while (!s.empty())
            {
                Node *t = s.top();
                s.pop();

                res.push_back(t->val);
                
                // stack all the children in reverse
                for (int i = t->children.size() - 1; i >= 0; --i)
                    s.push(t->children[i]);
            }

            return res;
        }
};