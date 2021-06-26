class Solution {
public:
    
    int getLen(string& s, int i, int j) {
        int n = s.size();
        if(i < 0 || j >= n) {
            return 0;
        }
        int ans = (i == j) ? -1 : 0;
        while(i >= 0 && j < n) {
            if(s[i--] != s[j++])    break;
            ans += 2;
        }
        return ans;
    }
    
    string longestPalindrome(string s) {
        int x = -1;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            int len = max(getLen(s, i, i), getLen(s, i, i+1));
            if(len > ans) {
                ans = len;
                x = i - ((len-1)>>1);
            }
        }
        return s.substr(x,ans);
    }
};
