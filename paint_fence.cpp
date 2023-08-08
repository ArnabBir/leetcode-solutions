// Link : https://leetcode.com/problems/paint-fence

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k*k;
        int prev = k;
        int curr = k*k;
        for (int i = 3; i <= n; ++i) {
            int next = (k-1)*(prev + curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};