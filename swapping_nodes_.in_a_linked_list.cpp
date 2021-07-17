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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = head;
        for(int i = 1; i < k; ++i) {
            n1 = n1->next;
        }
        ListNode* n2 = head;
        ListNode* end = head;
        for(int i = 0; i < k; ++i) {
            end = end->next;
        }
        while(end) {
            end = end->next;
            n2 = n2->next;
        }
        swap(n1->val, n2->val);
        return head;
    }
};
