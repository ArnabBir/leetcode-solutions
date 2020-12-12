class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<char> v(256,'#');
        vector<char> vinv(256,'#');
        for(int i = 0; i < n; ++i) {
            if(v[s[i]] == '#') {
                if(vinv[t[i]] == '#') {
                    v[s[i]] = t[i];
                    vinv[t[i]] = s[i];
                } else if(vinv[t[i]] != s[i]){
                    return false;
                }
            }
            else if(v[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }
};
