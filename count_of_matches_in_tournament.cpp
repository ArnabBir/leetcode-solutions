class Solution {
public:
    int numberOfMatches(int n) {
        if(n < 2)  return 0;
        return n/2 + numberOfMatches(n/2 + (n%2));
    }
};
