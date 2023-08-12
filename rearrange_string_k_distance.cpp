// Link : https://leetcode.com/problems/rearrange-string-k-distance-apart

class Solution {
public:
    string rearrangeString(string s, int k) {
        unordered_map<char,int> um;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++um[s[i]];
        }
        int max_freq = 0;
        for (auto it : um) {
            max_freq = max(max_freq, it.second);
        }
        unordered_set<char> max_chars, sec_max_chars;
        for (auto it : um) {
            if (it.second == max_freq) {
                max_chars.insert(it.first);
            } else if (it.second == max_freq-1) {
                sec_max_chars.insert(it.first);
            }
        }
        vector<string> segments(max_freq);
        for (int i = 0; i < max_freq; ++i) {
            for (char c : max_chars) {
                segments[i] += c;
            }
        }
        for (int i = 0; i < max_freq-1; ++i) {
            for (char c : sec_max_chars) {
                segments[i] += c;
            }
        }
        int x = 0;
        for (auto it : um) {
            char c = it.first;
            int count = it.second;
            if (max_chars.find(c) != max_chars.end() || sec_max_chars.find(c) != sec_max_chars.end()) {
                continue;
            }
            for (int i = 0; i < count; ++i) {
                segments[x] += c;
                x = (x+1) % (max_freq-1);
            }
        }
        s = "";
        for (int i = 0; i < max_freq-1; ++i) {
            //cout<<segments[i]<<endl;
            if (segments[i].size() < k) {
                return "";
            }
            s += segments[i];
        }
        s += segments.back();
        return s;
    }
};
