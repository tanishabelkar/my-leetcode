/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            if (head == nullptr)
                return nullptr;
            unordered_map<Node*, Node*> m;
            Node *res = new Node(head->val), *r = res, *h = head;
            m[head] = res;
            head = head->next;
            while (head)
            {
                r->next = new Node(head->val);
                m[head] = r->next;
                head = head->next;
                r = r->next;
            }

            r = res;
            while (r)
            {
                r->random = m[h->random];
                r = r->next;
                h = h->next;
            }

            return res;
        }
};