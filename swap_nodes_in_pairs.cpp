/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
*/
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **p = &head;   //use a pointer to pointer to make it easy to deal with the head
        while(*p && (*p)->next) {
            ListNode *cur = *p;
            *p = cur->next;
            cur->next = (*p)->next;
            (*p)->next = cur;
            p = &(cur->next);
        }
        return head;
    }
};
