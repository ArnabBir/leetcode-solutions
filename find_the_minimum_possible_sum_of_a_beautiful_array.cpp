// Link : https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array

class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long result = 0;
        long long num = 1;
        unordered_set<int> s;
        while (s.size() < n) {
            if (s.find(num) == s.end()) {
                result += num;
                s.insert(target-num);
            }
            ++num;
        }
        return result;
    }
};
