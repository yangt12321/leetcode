/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
*/
//complexity: log(k)*n
class cmp {
public:
    bool operator() (const ListNode *lhs, const ListNode *rhs) const {
        return (lhs->val > rhs->val);
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode *>::iterator iter = lists.begin();
        while(iter != lists.end() )
            *iter==NULL ? lists.erase(iter) : ++iter;
        ListNode *head = NULL, **tail = &head;
        make_heap(lists.begin(), lists.end(), cmp()); //rearrange the elements in the input vector to form a min heap 
        while(!lists.empty()) {
            *tail = lists[0];
            tail = &((*tail)->next);
            pop_heap(lists.begin(), lists.end(), cmp()); //pop the minimum element from the heap each time into the new list
            if(lists.back()->next) {
                lists.back() = lists.back()->next;
                push_heap(lists.begin(), lists.end(), cmp()); //automatically maintain heap propertities
            }
            else lists.pop_back();
        }
        return head;
    }
};
