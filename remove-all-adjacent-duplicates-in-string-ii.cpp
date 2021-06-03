class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        for(int i = 0; i < s.size(); ++i) {
            if(st.empty() || st.top().first != s[i]) {
                st.push(make_pair(s[i],1));
            }
            else if(st.top().first == s[i]) {
                ++st.top().second;
            }
            if(st.top().second % k == 0) {
                st.pop();
            }
            else if(st.top().second > k) {
                st.top().second -= k;
            }
        }
        string ans;
        while(!st.empty()) {
            while(st.top().second--) {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
