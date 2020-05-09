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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * mergedList = new ListNode();
        ListNode* head = mergedList;
        while(l1 != NULL && l2 != NULL) {
            int temp;
            if(l1->val <= l2->val) {
                temp = l1->val;
                l1 = l1->next;
            }
            else {
                temp = l2->val;
                l2 = l2->next;
            }
            mergedList->next = new ListNode(temp);
            mergedList = mergedList->next;
        }
        if(l1 != NULL) {
            mergedList->next = l1;
        }
        else if(l2 != NULL) {
            mergedList->next = l2;
        }
        return head->next;
    }  
};
