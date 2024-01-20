// Link : https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<int> ms, extra;
        for (int i = 0; i < dist+1; ++i) {
            ms.insert(nums[i+1]);
        }
        while (ms.size() > k-1) {
            int x = *ms.rbegin();
            ms.erase(ms.find(x));
            extra.insert(x);
        }
        long long currsum = 0;
        for (auto curr : ms) {
            currsum += curr;
        }
        long long minsum = currsum;
        for (int i = dist+2; i < n; ++i) {
            int remove = nums[i-dist-1];
            int add = nums[i];
            extra.insert(add);
            if (ms.find(remove) != ms.end()) {
                ms.erase(ms.find(remove));
                currsum -= remove;
                int minextra = *extra.begin();
                extra.erase(extra.find(minextra));
                ms.insert(minextra);
                currsum += minextra;
            } else {
                extra.erase(extra.find(remove));
            }
            if (ms.size() > 0 && extra.size() > 0 && *ms.rbegin() > *extra.begin()) {
                int large = *ms.rbegin();
                int small = *extra.begin();
                ms.erase(ms.find(large));
                extra.erase(small);
                ms.insert(small);
                extra.insert(large);
                currsum = currsum + small - large;
            }
            minsum = min(currsum, minsum);
        }
        return nums[0] + minsum;
    }
};
