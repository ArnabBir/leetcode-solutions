// Link : https://leetcode.com/problems/divide-chocolate/

class Solution {

public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = sweetness.size();
        int l = 1;
        int r = accumulate(sweetness.begin(), sweetness.end(), 0) / (k+1);
        int ans = 1;
        while (l <= r) {
            int m = l + (r-l)/2;
            int currs = 0, mins = INT_MAX, count = 0;
            int i;
            for (i = 0; i < n && count <= k; ++i) {
                currs += sweetness[i];
                if (currs >= m) {
                    mins = min(mins, currs);
                    ++count;
                    currs = 0;
                }
            }
            if (currs > 0) {
                mins = min(mins, currs);
                ++count;
            }
            if (count == k+1 && mins >= m) {
                l = m+1;
                ans = max(ans, m);
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};
