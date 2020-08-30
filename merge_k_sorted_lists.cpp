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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int n = lists.size();
        for(int i = 0; i < n; ++i) {
            if(lists[i]) {
                pq.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode* result = new ListNode();
        ListNode* temp = result;
        while(!pq.empty()) {
            pair<int, int> x = pq.top();
            temp->next = new ListNode(x.first);
            temp = temp->next;
            pq.pop();
            if(lists[x.second]) {
                pq.push(make_pair(lists[x.second]->val, x.second));
                lists[x.second] = lists[x.second]->next;
            }
        }
        return result->next;
    }
};
