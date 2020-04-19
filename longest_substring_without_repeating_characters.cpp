class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> visited(256, -1);
        int len = 0, max_len = 0;
        //visited[s[0]] = 0;
        for(int i = 0; i < n; ++i) {
            int prev = visited[s[i]];
            if((prev == -1) || (i - prev) > len) {
                ++len;
            }
            else {
                max_len = max(len, max_len);
                len = i - prev;
            }
            visited[s[i]] = i;
        }
        max_len = max(len, max_len);
        return max_len;
    }
};
