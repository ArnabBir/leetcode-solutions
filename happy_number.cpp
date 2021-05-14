class Solution {
    
public:
    bool isHappy(int n) {
        set<long> sums;
        if(n == 1)  return true;
        if(n < 7)  return false;
        long sum = 0;
        int x;
        while(n) {
            x = n%10;
            sum += x*x;
            n /= 10;
        }
        if(sums.find(sum) != sums.end()) return false;
        sums.insert(sum);
        if(sum == 1)    return true;
        double logval = log10(sum);
        if(logval == floor(logval)) return true;
        return isHappy((int)sum);
    }
};
