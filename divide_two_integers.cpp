class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) {
            return dividend;
        }
        if (divisor == INT_MIN) {
			if (dividend == INT_MIN)    return 1;
			return 0;
		}
        int ans = 0;
        bool positive = true;
        int half_int = 1073741824;
        if(dividend < 0 && divisor < 0) positive = true;
        else if(dividend < 0 || divisor < 0) positive = false;
        divisor = (divisor > 0) ? divisor : ~(divisor - 1);
        if (dividend == INT_MIN) {
			if (divisor == 1)
				return (positive) ? INT_MAX : INT_MIN;
			dividend += divisor;
			++ans;
		}
        dividend = (dividend > 0) ? dividend : ~(dividend - 1);        
        if(divisor == 1) {
            ans = (int)dividend;
        }
        else {
        while(dividend >= divisor) {
            int multiplier = 1;
            long value = divisor;
            while(value > 0 && value <= dividend) {
                multiplier <<= 1;
                value <<= 1;
            }
            value = (value >> 1) & ~(1 << 31);
            multiplier = (multiplier >> 1) & ~(1 << 31);
            dividend -= value;
            ans += (int)multiplier;
        }
        }
        return positive ? ans : -ans;
    }
};
