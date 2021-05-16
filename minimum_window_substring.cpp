class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t)  return s;
        int n = s.size();
        int m = t.size();
        if(m > n)   return "";
        vector<int> sc(256,0);
        vector<int> tc(256,0);
        for(int i = 0; i < m; ++i) {
            ++tc[t[i]];
        }
        int l, r, count = 0;
        int start = 0, end = n;
        bool flag = false;
        int min_len = n+1;
        for(l = 0, r = 0; r < n; ++r) {
            ++sc[s[r]];
            if(sc[s[r]] == tc[s[r]]) {
                count += sc[s[r]];
            }
            while(sc[s[l]] > tc[s[l]] && l < r) {
                --sc[s[l++]];
            }
            if(count == m) {
                flag = true;
                if((r-l+1) < min_len) {
                    min_len = r-l+1;
                    start = l;
                    end = r;
                }
            }
        }
        if(!flag)   return "";
        return s.substr(start, min_len);
    }
    
};
