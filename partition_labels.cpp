class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<pair<int, int>> v(26, make_pair(-1, -1));
        for(int i = 0; i < n; ++i) {
            if(v[s[i] - 'a'].first == -1 && v[s[i] - 'a'].second == -1) {
                v[s[i] - 'a'] = make_pair(i, i);
            }
            else {
                pair<int,int> p = v[s[i] - 'a'] ;
                int l = p.first;
                int r = p.second;
                if(i < l) l = i;
                else if(r < i) r = i;
                v[s[i] - 'a'] = make_pair(l,r);
            } 
        }
        vector<pair<int,int>> v1;
        for(int i = 0; i < 26; ++i) {
            if(v[i].first != -1) {
                v1.push_back(v[i]);
            }
        }
        sort(v1.begin(), v1.end());
        vector<pair<int,int>> w;
        w.push_back(v1[0]);
        for(int i = 1; i < v1.size(); ++i) {
            pair<int, int> p = w[w.size()-1];
            pair<int, int> n = v1[i];
            if(p.second >= n.first) {
                pair<int, int> m = make_pair(min(p.first, n.first), max(p.second, n.second));
                w.pop_back();
                w.push_back(m);
            }
            else {
                w.push_back(n);
            }
        }
        vector<int> result;
        for(int i = 0; i < w.size(); ++i) {
            pair<int, int> p = w[i];
            result.push_back(p.second - p.first + 1);
        }
        return result;
    }
};
