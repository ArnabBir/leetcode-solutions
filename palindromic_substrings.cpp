class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = n;
        for(int i  = 0; i < n; ++i) {
            for(int j = 2; i+j <= n; ++j) {
                string temp = s.substr(i,j);
                reverse(temp.begin(), temp.end());
                if(s.substr(i,j) == temp)   ++count;
            }
        }
        return count;
    }
};
