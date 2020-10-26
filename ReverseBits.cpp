class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos = 31, x;
        uint32_t ans = 0;
        while(n) {
            ans += (n%2)<<pos;
            --pos;
            n /= 2;
        }
        return ans;
    }
};
