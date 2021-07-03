class Solution {
public:
    int romanToInt(string s) {
        vector<int> v(256);
        v['I'] = 1;
        v['V'] = 5;
        v['X'] = 10;
        v['L'] = 50;
        v['C'] = 100;
        v['D'] = 500;
        v['M'] = 1000;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n-1; ++i) {
            if(v[s[i]] < v[s[i+1]]) {
                ans -= v[s[i]];
            }
            else {
                ans += v[s[i]];
            }
        }
        ans += v[s[n-1]];
        return ans;
    }
};
