class Solution {
public:
    string reverseWords(string s) {
        if(s.find(" ") == string::npos)  return s;
        int n = s.size();
        string ans = "";
        string temp = "";
        for(int i = n-1; i >= 0; --i) {
            if(s[i] == ' ') {
                if(temp != "") {
                    if(ans != "") ans += ' ' + temp;
                    else    ans += temp;
                    temp = "";
                }
            }
            else {
                temp = s[i] + temp;
            }
        }
        if(temp != "") {
                    ans += ' ' + temp;
                    temp = "";
                }
        return ans;
    }
};
