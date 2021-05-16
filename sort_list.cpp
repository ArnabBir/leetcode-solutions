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
    
    ListNode* mergeSort(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* node1 = head;
        ListNode* node2 = head;
        ListNode* node3 = head;
        while(node3 && (node3->next)) {
            node3 = node3->next->next;
            if(node3)   node2 = node2->next;
        }
        // if(node3) {
        //     node2 = node2->next;
        // }
        ListNode* m = node2;
        node2 = node2->next;
        m->next = NULL;
        node1 = mergeSort(node1);
        node2 = mergeSort(node2);
        ListNode* mergedNode = new ListNode();
        ListNode* node = mergedNode;
        while(node1 != NULL && node2 != NULL) {
            if(node1->val > node2->val) {
                cout<<node2->val<<endl;
                node->next = new ListNode(node2->val);
                node2 = node2->next;
            }
            else{
                node->next = new ListNode(node1->val);
                node1 = node1->next;
            }
            node = node->next;
        }
        while(node1 != NULL) {
            node->next = new ListNode(node1->val);
            node1 = node1->next;
            node = node->next;
        }
        while(node2 != NULL) {
            node->next = new ListNode(node2->val);
            node2 = node2->next;
            node = node->next;
        }
        return mergedNode->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        return mergeSort(head);
    }
};
