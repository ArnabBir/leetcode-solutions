/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* n1 = head->next;
        ListNode* n2 = head->next->next;
        while(n2 && n2->next) {
            if(n1 == n2)    break;
            n1 = n1->next;
            n2 = n2->next->next;
        }
        if(!n2 || n1 != n2) return nullptr;
        n2 = head;
        while(n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n2;
    }
};
