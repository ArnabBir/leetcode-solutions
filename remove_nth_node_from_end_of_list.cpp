/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode * ptr1 = head;
        ListNode * ptr2 = head;
        for(int i = 0; i < n; ++i) {
            if(ptr2 == NULL)    return head;
            ptr2 = ptr2->next;
        }
        if(ptr2 == NULL) {
            return head->next;
        }
        while(ptr2 != NULL && ptr2->next != NULL) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if(ptr1 != NULL && ptr1->next != NULL) {
            ptr1->next = ptr1->next->next;
        }
        return head;
    }
};
