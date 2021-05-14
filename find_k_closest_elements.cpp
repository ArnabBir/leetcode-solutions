class Solution {
public:
    
    struct comparator {
        bool operator()(pair<long,int> a, pair<long,int> b) {
            if(a.first > b.first)   return true;
            if(a.first < b.first)   return false;
            return a.second > b.second;
        }
    };
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<long,int>, vector<pair<long,int>>, comparator> pq;
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            pq.push(make_pair(abs(arr[i] - x), arr[i]));
        }
        vector<int> result;
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};
