class Solution {
public:
    int xorOperation(int n, int start) {
        if(start%4 < 2) {
        if(n%4 == 0) {
            return 0;
        }
        if(n%2 == 0) {
            return 2;
        }
        int nth = start + 2*(n-1);
        if(n%4 == 1) {
            return nth;
        }
        return nth^2;
        }
        else {
            int ans = start;
            while(n-1) {
                start += 2;
                ans ^= start;
                --n;
            }
            return ans;
        }
    }
};
