// Link : https://leetcode.com/problems/remove-9/description/

class Solution {
public:
    int newInteger(int n) {
        string ans;
        if (n < 9) {
            return n;
        }
        if (n == 9) {
            return 10;
        }
        while (n > 0) {
            ans += to_string(n%9);
            n /= 9;
        }
        reverse(ans.begin(), ans.end());
        return (int) stoi(ans); 
    }
};

/*
1 9 -> 1 [9]
10 99 -> 19, 29, 89, 90, 99 -> 9 + 1 
100 999 -> 109, 119 , 999, 
*/
