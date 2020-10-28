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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int decimalSum, carry = 0;
        
        ListNode * ln = new ListNode(0);
        ListNode * temp = ln;
        
        while(l1 != NULL || l2 != NULL){
            
            temp->next = new ListNode(0);
            temp = temp->next;
            
            if(l1 != NULL && l2 != NULL){
                
                decimalSum = l1->val + l2->val;
                temp->val = ((decimalSum + carry) %10);
                carry = (decimalSum + carry) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            
            else if(l1 != NULL){
                
                temp->val = ((l1->val + carry) % 10);
                carry = (l1->val + carry) / 10;
                l1 = l1->next;
            }
             
            else if(l2 != NULL){
                
                temp->val = ((l2->val + carry) % 10);
                carry = (l2->val + carry) / 10;
                l2 = l2->next;
            }
        }
        if(carry != 0) {
            temp->next = new ListNode(carry);
        }
        
        return ln->next;
    }
};
