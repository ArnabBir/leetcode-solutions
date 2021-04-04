/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return NULL;
        Node* new_head = new Node(0);
        Node* temp1 = head;
        Node* temp2 = new_head;
        Node* prev = NULL;
        while(temp1 != NULL) {
            temp2->val = temp1->val;
            temp2->next = new Node(0);
            prev = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        prev->next = NULL;
        temp1 = head;
        temp2 = new_head;
        while(temp1 != NULL) {
            Node* random = temp1->random;
            if(random == NULL) {
                temp2->random = NULL;
            }
            else {
                Node* temp3 = head;
                int k = 0;
                while(temp3 != random) {
                    temp3 = temp3->next;
                    ++k;
                }
                Node* temp4 = new_head;
                for(int i = 0; i < k; ++i) {
                    temp4 = temp4->next;
                }
                temp2->random = temp4;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return new_head;
    }
};
