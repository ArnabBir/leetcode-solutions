class Solution {
public:
    int reverse(int z) {
        bool neg = (z<0);
        long x = neg ? -(long)z : (long)z;
        long y = 0;
        while(x) {
            y += x%10;
            y *= 10;
            x /= 10;
        }
        if((y/10) >= (INT_MAX-1)) {
            y = 0;
        }
        y = neg ? -y : y;
        y = (int)(y/10);
        return y;
    }
};
