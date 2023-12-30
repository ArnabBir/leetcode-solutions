// Link : https://leetcode.com/problems/minimum-time-to-build-blocks/submissions/1132258173/

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        int n = blocks.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int block : blocks) {
            pq.push(block);
        }
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(split + max(x,y));
        }
        return pq.top();
    }
};