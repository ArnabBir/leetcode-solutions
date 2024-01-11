// Link : https://leetcode.com/problems/maximum-number-of-books-you-can-take/

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        vector<long long> diff(n), left_smaller(n, -1);
        vector<pair<int, int> > st;
        for (int i = 0; i < n; ++i) {
            diff[i] = books[i] - i;
        }
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.back().first >= diff[i]) {
                st.pop_back();
            }
            if (!st.empty()) {
                left_smaller[i] = st.back().second;
            }
            st.push_back({diff[i], i});
        }
        vector<long long> dp(n, 0);
        dp[0] = books[0];
        for (int i = 1; i < n; ++i) {
            int prev_smaller = left_smaller[i];
            long long elements_right;
            if (prev_smaller != -1) {
                elements_right = i - prev_smaller;
            } else {
                elements_right = min(i+1,  [i]);
            }
            long long last = books[i];
            long long first = books[i] - elements_right + 1;
            dp[i] = ((first + last) * elements_right) / 2;
            if (prev_smaller != -1) {
                dp[i] += dp[prev_smaller];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
