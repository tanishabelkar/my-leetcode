/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {
            if (!head)
                return nullptr;
            ListNode *slow = head, *fast = head->next;
            while (slow != nullptr && fast != nullptr && fast->next != nullptr)
            {
                if (slow == fast)
                {
                    ListNode *res = head;
                    while (slow->next != res)
                    {
                        slow = slow->next;
                        res = res->next;
                    }
                    return res;
                }
                slow = slow->next;
                fast = fast->next->next;
            }
            return nullptr;
        }
};