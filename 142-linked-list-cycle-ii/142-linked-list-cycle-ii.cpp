/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {
            if (!head)
                return nullptr;
            unordered_map<ListNode*, int> m;
            ListNode *beg = head;
            while (beg != nullptr)
            {
                m[beg] += 1;
                if (m[beg] > 1)
                    return beg;
                beg = beg->next;
            }
            return nullptr;
        }
};