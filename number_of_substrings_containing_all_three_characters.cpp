class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int start = -1;
        int ans = 0;
        vector<int> count(3,0);
        for(; r<n; ++r) {
            ++count[s[r]-'a'];
            if(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                while(count[s[l]-'a'] > 1) {
                    --count[s[l++]-'a'];
                }
                ans += (l-start) * (n-r);
                start = l;
            }
        }
        return ans;
    }
};
