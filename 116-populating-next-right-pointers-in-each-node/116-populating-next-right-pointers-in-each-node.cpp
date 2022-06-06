/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    map<int, vector<Node*>> m;
    
    void travel(Node* r, int l)
    {
        if(!r)
            return;
        m[l].push_back(r);
        travel(r->left, l+1);
        travel(r->right, l+1);
    }
    
    Node* connect(Node* root)
    {
        if(!root)
            return nullptr;
        travel(root, 0);
        for(auto it:m)
        {
            for(int i=0;i<it.second.size()-1;++i)
            {
                it.second[i]->next=it.second[i+1];
            }
            it.second.back()->next=nullptr;
        }
        return root;
    }
};