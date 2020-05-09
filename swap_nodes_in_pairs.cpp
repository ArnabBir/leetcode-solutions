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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p1 != NULL && p2 != NULL) {
            int temp = p1->val; 
            p1->val = p2->val;
            p2->val = temp;
            if(p2->next != NULL) {
                p1 = p2->next;
                p2 = p1->next;
            }
            else {
                break;
            }
        }
        return head;
    }
};
