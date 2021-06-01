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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        for(int i = 0; i < left-1; ++i) {
            temp = curr;
            curr = curr->next;
        }
        temp1 = curr;
        for(int i = left; i < right; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        temp2 = curr->next;
        curr->next = prev;
        temp1->next = temp2;
        if(temp) {
            temp->next = curr;
            return head;
        }
        return curr;
    }
};
