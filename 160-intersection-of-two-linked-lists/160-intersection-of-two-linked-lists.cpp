/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *a=headA, *b=headB;
        
        if(a==nullptr || b==nullptr)
            return nullptr;
        
        while(a!=nullptr)
        {
            b=headB;
            while(b!=nullptr)
            {
                if(b == a)
                    return a;
                b=b->next;
            }
            a=a->next;
        }
        
        return nullptr;
    }
};