/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;(
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)    return head;
        ListNode * pt1x = head;
        ListNode * pt2x = head;
        while(pt2x->next != NULL) {
            if(pt2x->next->next == NULL) {
                return pt1x->next;
            }
            pt1x = pt1x->next;
            pt2x = pt2x->next->next;
        }
        return pt1x;
    }
};
