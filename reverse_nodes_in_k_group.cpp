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

private:
    void reverseList(ListNode* s, ListNode* e) {
        ListNode* curr = s;
        ListNode* past = e;
        ListNode* next = curr->next;
        while (curr != NULL && curr != e) {
            curr->next = past;
            past = curr;
            curr = next;
            if(curr != NULL) {
                next = curr->next;
            }
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* s = head;
        ListNode* x = head->next;
        ListNode* e;
        ListNode* p = NULL;
        int n = 1;
        bool firstFlip = true;
        while(x != NULL) {
            if(n == k-1) {
                e = x->next;
                if(firstFlip) {
                    head = x;
                    firstFlip = false;
                }
                reverseList(s, e);
                if(p != NULL) {
                    p->next = x;
                }
                p = s;
                s = e;
                if(s == NULL)   break;
                x = s->next;
                n = 1;
            }
            else {
                x = x->next;
                ++n;
            }
        }
        return head;
    }
};
