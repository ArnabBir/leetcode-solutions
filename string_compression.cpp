class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        int ans = 0;
        int n = chars.size();
        vector<char> result;
        for(int i = 0; i <= n; ++i) {
            if(i == 0 || count == 0) {
                count = 1;
            }
            else if(i == n) {
                result.push_back(chars[i-1]);
                    if(count > 1) {
                        vector<char> count_v;
                        while(count) {
                            count_v.push_back((char)(count%10+'0'));
                            count /= 10;
                        }
                        reverse(count_v.begin(),count_v.end());
                        result.insert(result.end(), count_v.begin(), count_v.end());
                    }
            }
            else {
                if(chars[i-1] == chars[i]) {
                    ++count;
                }
                else {
                    result.push_back(chars[i-1]);
                    if(count > 1) {
                        vector<char> count_v;
                        while(count) {
                            count_v.push_back((char)(count%10+'0'));
                            count /= 10;
                        }
                        reverse(count_v.begin(),count_v.end());
                        result.insert(result.end(), count_v.begin(), count_v.end());
                    }
                    count = 1;
                }
            }
        }
        chars = result;
        return chars.size(); 
    }
};
