class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> um;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; ++i) {
            ++um[nums[i]];
        }
        for(auto & it : um) {
            pq.push(make_pair(it.second, it.first));
        }
        vector<int> result;
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
