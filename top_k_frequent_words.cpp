struct comparator {
    bool operator()(pair<int, string> p1, pair<int, string> p2) {
        if(p1.first < p2.first) return true;
        if(p1.first > p2.first) return false;
        return p1.second >= p2.second;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        sort(words.begin(), words.end());
        if(n == k)  return words;
        map<string, int> um;
        for(int i = 0; i < n; ++i) {
            ++um[words[i]];
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        for(auto & x : um) {
            //cout<<x.second<<" "<<x.first<<endl;
            pq.push(make_pair(x.second, x.first));
        }
        vector<string> result;
        while(k--) {
            pair<int, string> p = pq.top();
            pq.pop();
            cout<<p.second<<" "<<p.first<<endl;
            result.push_back(p.second);
        }
        return result;
    }
};
