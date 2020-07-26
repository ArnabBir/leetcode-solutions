class Solution {
public:
    string countAndSay(int n) {
        
        string ans = "1", temp = "";        
        int x = 0, y = 0;
        for(int i = 1; i < n; ++i) {
           while(y < ans.size()) {
               while(ans[y] == ans[x]) {
               ++y;
               }
               temp += to_string(y-x) + to_string(ans[x]-'0');
               x=y;
           } 
           ans = temp;
           temp = "";
           x = y = 0;
        }
        return ans;
    }
};
