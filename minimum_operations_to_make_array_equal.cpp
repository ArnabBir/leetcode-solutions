class Solution {
public:
    int minOperations(int n) {
        int x = n/2;
        if(n%2) return x*(x+1);
        return x*x;
    }
};
