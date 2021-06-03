class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(um.find(s[i]) == um.end()) {
                um[s[i]] = i;
            }
            else {
                um[s[i]] = INT_MAX;
            }
        }
        int minidx = INT_MAX;
        for(auto & x : um) {
            minidx = min(minidx, x.second);
        }
        return minidx == INT_MAX ? -1 : minidx;
    }
};
