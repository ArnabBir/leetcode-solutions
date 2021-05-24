class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c(26,0);
        int n = s.size();
        int m = t.size();
        for(int i = 0; i < n; ++i) {
            ++c[s[i]-'a'];
        }
        for(int i = 0; i < m; ++i) {
            --c[t[i]-'a'];
        }
        for(int i = 0; i < 26; ++i) {
            if(c[i])    return false;
        }
        return true;
    }
};
