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
    bool hasCycle(ListNode *head) {
        ListNode* n1 = head;
        ListNode* n2 = head;
        if(!head || !head->next) return false;
        do {
            n1 = n1->next;
            n2 = n2->next->next;
        }while(n2 && n2->next && n1 != n2);
        if(n1 != n2) return false;
        return true;
    }
};
