class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num+1);
        v[0] = 0;
        int x = 0;
        for(int i = 1; i <= num; ++i) {
            if(i > 1 && !(i&(i-1))) {
                x = 0;
            }
            v[i] = v[x++] + 1;
        }
        return v;
    }
};
