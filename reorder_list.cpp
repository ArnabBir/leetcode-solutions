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
    
    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        ListNode* next = nullptr;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node != nullptr) {
            ++n;
            node = node->next;
        }
        if(n < 3)   return;
        int m = (int)ceil(n/2);
        node = head;
        for(int i = 0; i < m; ++i) {
            node = node->next;
        }
        ListNode* temp = node->next;
        node->next = nullptr;
        ListNode* temp3 = reverse(temp);
        ListNode* n1 = head;
        ListNode* n2 = temp3;
        while(n2) {
            ListNode* temp1 = n1->next;
            ListNode* temp2 = n2->next;
            n1->next = n2;
            n2->next = temp1;
            n1 = temp1;
            n2 = temp2;
        }
    }
};
