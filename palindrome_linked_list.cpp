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
    
    ListNode* reverse(ListNode * node) {
        
        ListNode* prev = NULL;
        ListNode* curr = node->next;
        ListNode* next  = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL) {
            temp = temp->next;
            ++n;
        }
        if(n < 2)   return true;
        if(n == 2)  return head->val == head->next->val;
        if(n == 3)  return head->val == head->next->next->val;
        bool oddlen = n%2;
        temp = head;
        ListNode* l1 = head, *l2;
        if(oddlen) {
            for(int i = 0; i <= n/2; ++i) {
                temp = temp->next;
            }
        }
        else {
            for(int i = 0; i < n/2; ++i) {
                temp = temp->next;
            }
        }
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* next  = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev;
        bool palin = true;
        for(int i = 0; i < n/2; ++i) {
            cout<<l1->val<<" "<<l2->val<<endl;
            if(l1->val != l2->val) {
                palin = false;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return palin;
    }
};
