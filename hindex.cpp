// Link : https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            if (citations[i] == i+1) {
                return citations[i];
            }
            if (citations[i] < i+1) {
                return i;
            }
        }
        return n;
    }
};