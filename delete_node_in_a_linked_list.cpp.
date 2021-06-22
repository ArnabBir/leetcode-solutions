class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        Node* prev = del;
       while(del->next != NULL) {
           del->data = del->next->data;
           prev = del;
           del = del->next;
       }
       prev->next = nullptr;
    }
};
