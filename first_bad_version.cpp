// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadVersionUtil(int l, int r) {
        if(l >= r)  return l;
        int m = l + ((r-l)>>1);
        if(isBadVersion(m)) {
            return firstBadVersionUtil(l, m);
        }
        else {
            return firstBadVersionUtil(m+1,r);
        }
    }
    
    int firstBadVersion(int n) {
        return firstBadVersionUtil(1,n);
    }
};
